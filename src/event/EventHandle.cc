#include "event/EventHandle.h"

EventHandle::EventHandle(const std::vector<TString>& file_locations, const bool& is_mc): _is_mc{is_mc}, _data{new TChain("tree/physics")}, _buffer{}, _event{}, _corrector{"rcdata.2016.v3"}
{
	std::cout << "Initializing EventHandle..." << std::endl << std::endl;
	for (const auto& file_location : file_locations)
	{
		_data->Add(file_location);
		std::cout << file_location << " added" << std::endl;
	}
	std::cout << std::endl;
	_buffer.SetBranchRead(_data);
}

void EventHandle::SetBranchStatus()
{
	std::vector<TString> branch_names{};
	branch_names.push_back("weight");
	branch_names.push_back("num_filters");
	branch_names.push_back("num_triggers");
	branch_names.push_back("num_electrons");
	branch_names.push_back("num_muons");
	branch_names.push_back("num_photons");
	branch_names.push_back("filter_name");
	branch_names.push_back("filter_decision");
	branch_names.push_back("trigger_name");
	branch_names.push_back("trigger_decision");
	branch_names.push_back("electron_corrected_pt");
	branch_names.push_back("electron_sc_eta");
	branch_names.push_back("electron_sc_phi");
	branch_names.push_back("electron_pass_cutbased_loose");
	branch_names.push_back("electron_sigmaIetaIeta");
	branch_names.push_back("electron_dEtaInSeed");
	branch_names.push_back("electron_dPhiIn");
	branch_names.push_back("electron_hOverE");
	branch_names.push_back("electron_isoRho");
	branch_names.push_back("electron_ooEmooP");
	branch_names.push_back("electron_expectedMissingInnerHits");
	branch_names.push_back("electron_passConversionVeto");
	branch_names.push_back("electron_miniiso_ea");
	branch_names.push_back("muon_pt");
	branch_names.push_back("muon_eta");
	branch_names.push_back("muon_phi");
	branch_names.push_back("muon_isPFMuon");
	branch_names.push_back("muon_isGlobalMuon");
	branch_names.push_back("muon_isTrackerMuon");
	branch_names.push_back("muon_inner_numberOfValidPixelHits");
	branch_names.push_back("muon_inner_trackerLayersWithMeasurement");
	branch_names.push_back("muon_global_numberOfValidMuonHits");
	branch_names.push_back("muon_numberOfMatchedStations");
	branch_names.push_back("muon_best_dxy_vtx");
	branch_names.push_back("muon_best_dz_vtx");
	branch_names.push_back("muon_best_pt");
	branch_names.push_back("muon_best_ptError");
	branch_names.push_back("muon_isolationR03_sumpt");
	branch_names.push_back("photon_corrected_pt");
	branch_names.push_back("photon_sc_eta");
	branch_names.push_back("photon_sc_phi");
	branch_names.push_back("photon_pass_mva_wp80");
	branch_names.push_back("photon_pass_mva_wp90");
	branch_names.push_back("photon_pass_conversion_veto");

	if (_is_mc)
	{
		branch_names.push_back("num_gen_particles");
		branch_names.push_back("gen_particle_pt");
		branch_names.push_back("gen_particle_eta");
		branch_names.push_back("gen_particle_phi");
		branch_names.push_back("gen_particle_mass");
		branch_names.push_back("gen_particle_charge");
		branch_names.push_back("gen_particle_id");
		branch_names.push_back("gen_particle_fromHardProcessFinalState");
		branch_names.push_back("gen_particle_isHardProcess");
		branch_names.push_back("gen_particle_isPromptFinalState");
	}
	
	_data->SetBranchStatus("*", 0);
	for (const auto& branch_name : branch_names)
	{
		_data->SetBranchStatus(branch_name, "1");
	}
}

void EventHandle::MuonMomentumCorrection()
{
	double scale_factor = 1.;
	double u1, u2;
	for (auto i = 0; i < _buffer.num_muons; ++i)
	{
		if (_is_mc) 
		{
			u1 = gRandom->Rndm(), u2 = gRandom->Rndm();
			scale_factor = _corrector.kScaleAndSmearMC(_buffer.muon_charge[i], _buffer.muon_pt[i], _buffer.muon_eta[i], _buffer.muon_phi[i], _buffer.muon_inner_trackerLayersWithMeasurement[i], u1, u2, 0, 0);
		}
		else
		{
			scale_factor = _corrector.kScaleDT(_buffer.muon_charge[i], _buffer.muon_pt[i], _buffer.muon_eta[i], _buffer.muon_phi[i], 0, 0);
		}
		_buffer.muon_corrected_pt[i] = _buffer.muon_pt[i] * scale_factor;
	}
}

void EventHandle::ReconstructEventFromBuffer()
{
	_event.SetRunNumber(_buffer.run);
	_event.SetLS(_buffer.ls);
	_event.SetEventNumber(_buffer.event);
	_event.SetNumVertices(_buffer.num_vertices);
	_event.SetNumPU(_buffer.num_pu);
	_event.SetWeight(_buffer.weight);

	std::vector<TriggerResult> filters{};
	for (auto i = 0; i < _buffer.num_filters; ++i)
	{
		filters.emplace_back(_buffer.filter_name->at(i), _buffer.filter_decision[i]);
	}
	_event.SetFilterResults(std::move(filters));

	std::vector<TriggerResult> triggers{};
	for (auto i = 0; i < _buffer.num_triggers; ++i)
	{
		triggers.emplace_back(_buffer.trigger_name->at(i), _buffer.trigger_decision[i]);
	}
	_event.SetTriggerResults(std::move(triggers));

	std::vector<Electron> electrons{};
	for (auto i = 0; i < _buffer.num_electrons; ++i)
	{
		electrons.emplace_back(_buffer.electron_corrected_pt[i], _buffer.electron_sc_eta[i], _buffer.electron_sc_phi[i], _buffer.electron_pass_cutbased_loose[i],
		_buffer.electron_sigmaIetaIeta[i], _buffer.electron_dEtaInSeed[i], _buffer.electron_dPhiIn[i], _buffer.electron_hOverE[i],
		_buffer.electron_isoRho[i], _buffer.electron_ooEmooP[i], _buffer.electron_expectedMissingInnerHits[i], _buffer.electron_passConversionVeto[i],
		_buffer.electron_miniiso_ea[i]);
	}
	_event.SetElectrons(std::move(electrons));

	std::vector<Muon> muons{};
	for (auto i = 0; i < _buffer.num_muons; ++i)
	{
		muons.emplace_back(_buffer.muon_corrected_pt[i], _buffer.muon_eta[i], _buffer.muon_phi[i], _buffer.muon_isPFMuon[i], _buffer.muon_isGlobalMuon[i], _buffer.muon_isTrackerMuon[i],
		_buffer.muon_global_numberOfValidMuonHits[i], _buffer.muon_inner_numberOfValidPixelHits[i], _buffer.muon_inner_trackerLayersWithMeasurement[i], _buffer.muon_numberOfMatchedStations[i],
		_buffer.muon_best_dxy_vtx[i], _buffer.muon_best_dz_vtx[i], _buffer.muon_best_pt[i], _buffer.muon_best_ptError[i], _buffer.muon_isolationR03_sumpt[i]);
	}
	_event.SetMuons(std::move(muons));

	std::vector<Photon> photons{};
	for (auto i = 0; i < _buffer.num_photons; ++i)
	{
		photons.emplace_back(_buffer.photon_corrected_pt[i], _buffer.photon_sc_eta[i], _buffer.photon_sc_phi[i], _buffer.photon_pass_mva_wp80[i], _buffer.photon_pass_mva_wp90[i], _buffer.photon_pass_conversion_veto[i], _buffer.photon_has_pixel_seed[i]);
	}
	_event.SetPhotons(std::move(photons));

	std::vector<GenParticle> gen_particles{};
	for (auto i = 0; i < _buffer.num_gen_particles; ++i)
	{
		gen_particles.emplace_back(_buffer.gen_particle_pt[i], _buffer.gen_particle_eta[i], _buffer.gen_particle_phi[i], _buffer.gen_particle_mass[i],
		_buffer.gen_particle_charge[i], _buffer.gen_particle_id[i], _buffer.gen_particle_fromHardProcessFinalState[i], _buffer.gen_particle_isHardProcess[i], _buffer.gen_particle_isPromptFinalState[i]);
	}
	_event.SetGenParticles(std::move(gen_particles));
}

const Event& EventHandle::GetEvent(const int& entry_number)
{
	_data->GetEntry(entry_number);
	MuonMomentumCorrection();
	ReconstructEventFromBuffer();
	return _event;
}

int EventHandle::NumberOfEvents() const
{
	return _data->GetEntries();
}
