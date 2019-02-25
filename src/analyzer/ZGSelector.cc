#include "analyzer/ZGSelector.h"

void ZGSelector::SetLeadingElectronPtThreshold(const double& threshold)
{
    _eeg_leading_pt_cut = threshold;
    std::cout << "Electron leading pt threshold: " << _eeg_leading_pt_cut << std::endl << std::endl;
}

void ZGSelector::SetSubleadingElectronPtThreshold(const double& threshold)
{
    _eeg_subleading_pt_cut = threshold;
    std::cout << "Electron subleading pt threshold: " << _eeg_subleading_pt_cut << std::endl << std::endl;
}

void ZGSelector::SetLeadingMuonPtThreshold(const double& threshold)
{
    _mmg_leading_pt_cut = threshold;
    std::cout << "Muon leading pt threshold: " << _mmg_leading_pt_cut << std::endl << std::endl;
}

void ZGSelector::SetSubleadingMuonPtThreshold(const double& threshold)
{
    _mmg_subleading_pt_cut = threshold;
    std::cout << "Muon subleading pt threshold: " << _mmg_subleading_pt_cut << std::endl << std::endl;
}

void ZGSelector::SetElectronChannelPhotonPtThreshold(const double& threshold)
{
    _eeg_pho_pt_cut = threshold;
    std::cout << "Electron channel photon pt threshold: " << _eeg_pho_pt_cut << std::endl << std::endl;
}

void ZGSelector::SetMuonChannelPhotonPtThreshold(const double& threshold)
{
    _mmg_pho_pt_cut = threshold;
    std::cout << "Muon channel photon pt threshold: " << _mmg_pho_pt_cut << std::endl << std::endl;
}

void ZGSelector::SetElectronChannelPhotonEtaRestriction(const double& threshold)
{
    _eeg_pho_eta_cut = threshold;
    std::cout << "Electron channel photon eta restriction: " << _eeg_pho_eta_cut << std::endl << std::endl;
}

void ZGSelector::SetMuonChannelPhotonEtaRestriction(const double& threshold)
{
    _mmg_pho_eta_cut = threshold;
    std::cout << "Muon channel photon eta restriction: " << _mmg_pho_eta_cut << std::endl << std::endl;
}

void ZGSelector::SetPhotonPtOverMassThreshold(const double& threshold)
{
    _pho_pt_over_llg_mass_cut = threshold;
    std::cout << "Photon pt / llg mass threshold: " << _pho_pt_over_llg_mass_cut << std::endl << std::endl;
}

void ZGSelector::SetPhotonIdentificationWP(const int& wp)
{
    _pho_mva_wp = wp;
    std::cout << "Photon MVA WP: " << _pho_mva_wp << "%" << std::endl << std::endl;
}

void ZGSelector::SetPhotonVetoElectron(const int& veto_num)
{
    _pho_veto_el = veto_num;
    auto veto_name = (_pho_veto_el == 0) ? "CESV" : "pixel seed veto";
    std::cout << "Veto: " << veto_name << std::endl << std::endl;
}

void ZGSelector::SetElectronChannelTriggers(const std::vector<TString>& triggers)
{
    _eeg_triggers = triggers;
    std::cout << "Electron channel triggers: " << std::endl;
    for (const auto& trigger : _eeg_triggers) std::cout << trigger << std::endl;
    std::cout << std::endl;
}

void ZGSelector::SetMuonChannelTriggers(const std::vector<TString>& triggers)
{
    _mmg_triggers = triggers;
    std::cout << "Muon channel triggers: " << std::endl;
    for (const auto& trigger : _mmg_triggers) std::cout << trigger << std::endl;
    std::cout << std::endl;
}

void ZGSelector::SetOutputPath(const TString& output_path)
{
    _output_path = output_path;
    std::cout << "Output: " << _output_path << std::endl << std::endl;
}

double ZGSelector::DeltaR(const std::pair<double, double>& eta1_phi1, const std::pair<double, double>& eta2_phi2)
{
    auto dEta = fabs(eta1_phi1.first - eta2_phi2.first);
    auto dPhi = fabs(eta1_phi1.second - eta2_phi2.second);
    if (dPhi > M_PI) dPhi = 2 * M_PI - dPhi;
    return sqrt(dEta * dEta + dPhi * dPhi);
}

ZGSelector::ZGSelector(const bool& is_mc, const bool& is_zg, const bool& is_dy)
:_is_mc{is_mc}, _is_zg{is_zg}, _is_dy{is_dy}, _eeg_events{"eeg", "eeg"}, _mmg_events{"mmg", "mmg"}
{
    std::cout << "Initializing ZGSelector..." << std::endl << std::endl;

    std::cout << "Is MC?: " << _is_mc << std::endl;
    std::cout << "Is ZG?: " << _is_zg << std::endl;
    std::cout << "Is DY?: " << _is_dy << std::endl << std::endl;

    _eeg_events.Branch("lepton0_pt", &_lepton0_pt);
    _eeg_events.Branch("lepton0_eta", &_lepton0_eta);
    _eeg_events.Branch("lepton0_phi", &_lepton0_phi);
    _eeg_events.Branch("lepton1_pt", &_lepton1_pt);
    _eeg_events.Branch("lepton1_eta", &_lepton1_eta);
    _eeg_events.Branch("lepton1_phi", &_lepton1_phi);
    _eeg_events.Branch("photon_pt", &_photon_pt);
    _eeg_events.Branch("photon_eta", &_photon_eta);
    _eeg_events.Branch("photon_phi", &_photon_phi);
    _eeg_events.Branch("m_llg", &_m_llg);
    _eeg_events.Branch("gen_weight", &_gen_weight);
    _eeg_events.Branch("gen_photon_pt", &_gen_photon_pt);

    _mmg_events.Branch("lepton0_pt", &_lepton0_pt);
    _mmg_events.Branch("lepton0_eta", &_lepton0_eta);
    _mmg_events.Branch("lepton0_phi", &_lepton0_phi);
    _mmg_events.Branch("lepton1_pt", &_lepton1_pt);
    _mmg_events.Branch("lepton1_eta", &_lepton1_eta);
    _mmg_events.Branch("lepton1_phi", &_lepton1_phi);
    _mmg_events.Branch("photon_pt", &_photon_pt);
    _mmg_events.Branch("photon_eta", &_photon_eta);
    _mmg_events.Branch("photon_phi", &_photon_phi);
    _mmg_events.Branch("m_llg", &_m_llg);
    _mmg_events.Branch("gen_weight", &_gen_weight);
    _mmg_events.Branch("gen_photon_pt", &_gen_photon_pt);
}

void ZGSelector::Select(const Event& event)
{
    auto triggered_by_electron = false, triggered_by_muon = false;

    for (const auto& trigger : _eeg_triggers) triggered_by_electron = triggered_by_electron || event.IsTriggered(trigger);
    for (const auto& trigger : _mmg_triggers) triggered_by_muon = triggered_by_muon || event.IsTriggered(trigger);

    if (!triggered_by_electron && !triggered_by_muon) return;

    auto good_vertice = event.IsFiltered("Flag_goodVertices");

    if (!_is_mc && !good_vertice) return;

    _gen_weight = event.Weight();

    auto electron_selection = SelectElectrons(event);
    auto muon_selection = SelectMuons(event);

    auto electrons = electron_selection.first;
    auto muons = muon_selection.first;

    auto req_on_electrons = electron_selection.second;
    auto req_on_muons = muon_selection.second;
    
    auto veto_el = (electrons.size() == 0);
    auto veto_mu = (muons.size() == 0);

    auto eeg = (triggered_by_electron && req_on_electrons && veto_mu);
    auto mmg = (!triggered_by_electron && triggered_by_muon && req_on_muons && veto_el);

    if (!eeg && !mmg) return;

    auto& leptons = (eeg) ? electrons : muons;     

    auto m_ll = (leptons[0] + leptons[1]).M();
    if (m_ll < 50 || m_ll > 130) return;

    auto photon_selection = SelectPhotons(event, leptons);
    auto photons = photon_selection.first;
    auto req_on_photons = photon_selection.second;
    
    if (!req_on_photons) return;

    _photon_pt = photons[0].Pt();
    _photon_eta = photons[0].Eta();
    _photon_phi = photons[0].Phi();
    _m_llg = (leptons[0] + leptons[1] + photons[0]).M();

    if (_photon_pt / _m_llg < _pho_pt_over_llg_mass_cut) return;

    if (_is_zg)
    {
        FillGenPhotonPt(event);
    }
    else if (_is_dy)
    {
        if (IsPromptPhoton(photons[0], event)) return;
    }

    _lepton0_pt = leptons[0].Pt();
    _lepton0_eta = leptons[0].Eta();
    _lepton0_phi = leptons[0].Phi();
    _lepton1_pt = leptons[1].Pt();
    _lepton1_eta = leptons[1].Eta();
    _lepton1_phi = leptons[1].Phi();

    if (eeg) _eeg_events.Fill();
    else _mmg_events.Fill();
}

std::pair<std::vector<TLorentzVector>, bool> ZGSelector::SelectElectrons(const Event& event)
{
    const auto& electrons = event.Electrons();
    std::vector<TLorentzVector> selected_electrons;
    auto electron_leading = false;
    
    for (const auto& electron : electrons)
    {
        if (electron.PassAcceptance(_eeg_subleading_pt_cut, 2.5) && electron.PassIdentification())
        {
            if (electron.Pt() > _eeg_leading_pt_cut) electron_leading = true;

            TLorentzVector electron_mom;
            electron_mom.SetPtEtaPhiM(electron.Pt(), electron.Eta(), electron.Phi(), electron.Mass());
            selected_electrons.push_back(electron_mom);
        }
    }
    auto req_on_electrons = (selected_electrons.size() == 2 && electron_leading);
    return {selected_electrons, req_on_electrons};
}

std::pair<std::vector<TLorentzVector>, bool> ZGSelector::SelectPhotons(const Event& event, const std::vector<TLorentzVector> leptons)
{
    const auto& photons = event.Photons();
    std::vector<TLorentzVector> selected_photons;

    for (const auto& photon : photons)
    {
        if (photon.PassAcceptance(_eeg_pho_pt_cut, _eeg_pho_eta_cut) && photon.PassIdentification(_pho_mva_wp) && photon.PassVeto(_pho_veto_el))
        {
            if (DeltaR({photon.Eta(), photon.Phi()}, {leptons[0].Eta(), leptons[0].Phi()}) > 0.4 && DeltaR({photon.Eta(), photon.Phi()}, {leptons[1].Eta(), leptons[1].Phi()}) > 0.4)
            {
                TLorentzVector photon_mom;
                photon_mom.SetPtEtaPhiM(photon.Pt(), photon.Eta(), photon.Phi(), 0);
                selected_photons.push_back(photon_mom);
            }
        }
    }

    auto req_on_photons = (selected_photons.size() == 1);

    return {selected_photons, req_on_photons};
}

std::pair<std::vector<TLorentzVector>, bool> ZGSelector::SelectMuons(const Event& event)
{
    const auto& muons = event.Muons();
    std::vector<TLorentzVector> selected_muons;

    bool muon_leading = false;
    bool muon_highpt = false;
    
    for (const auto& muon : muons)
    {
        if (muon.PassAcceptance(_mmg_subleading_pt_cut, 2.4) && (muon.PassIdentification() || muon.PassHighPtIdentification()))
        {
            if (muon.Pt() > _mmg_leading_pt_cut) muon_leading = true;
            if (muon.PassHighPtIdentification()) muon_highpt = true;

            TLorentzVector muon_mom;
            muon_mom.SetPtEtaPhiM(muon.Pt(), muon.Eta(), muon.Phi(), muon.Mass());
            selected_muons.push_back(muon_mom);
        }
    }

    auto req_on_muons = (selected_muons.size() == 2 && muon_highpt & muon_leading);

    return {selected_muons, req_on_muons};
}

void ZGSelector::FillGenPhotonPt(const Event& event)
{
    const auto& particles = event.GenParticles();
    for (const auto& particle : particles)
    {
        if (fabs(particle.ID()) == 22 && particle.IsHardProcess())
        {
            _gen_photon_pt = particle.Pt();
            break;
        }
    }
}

bool ZGSelector::IsPromptPhoton(const TLorentzVector& photon, const Event& event)
{
    auto is_prompt = false;
    const auto& particles = event.GenParticles();

    std::pair<double, double> photon_eta_phi = {photon.Eta(), photon.Phi()};

    for (const auto& particle : particles)
    {
        std::pair<double, double> particle_eta_phi = {particle.Eta(), particle.Phi()};
        if (fabs(particle.ID()) == 22 && particle.IsPromptFinalState() && DeltaR(photon_eta_phi, particle_eta_phi) < 0.2)
        {
            is_prompt = true;
            break;
        }
    }

    return is_prompt;
}

void ZGSelector::Save()
{
    std::cout << "Save the tree to " << _output_path << std::endl << std::endl;
    std::cout << "Total " << _eeg_events.GetEntries() << " events selected for the electron channel" << std::endl;
    std::cout << "Total " << _mmg_events.GetEntries() << " events selected for the muon channel" << std::endl << std::endl; 
    auto output_file = std::make_unique<TFile>(_output_path, "RECREATE");
    _eeg_events.Write();
    _mmg_events.Write();
}