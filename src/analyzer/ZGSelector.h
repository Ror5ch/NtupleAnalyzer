#ifndef _ZGSELECTOR_
#define _ZGSELECTOR_

#include <iostream>
#include <math.h>

#include "TFile.h"
#include "TString.h"
#include "TTree.h"

#include "analyzer/EventSelector.h"

class ZGSelector : public EventSelector
{
public:
	ZGSelector(const bool&, const bool&, const bool&);
	~ZGSelector() {};
	void Select(const Event&);
	void Save();
	void SetLeadingElectronPtThreshold(const double& threshold);
	void SetSubleadingElectronPtThreshold(const double& threshold);
	void SetLeadingMuonPtThreshold(const double& threshold);
	void SetSubleadingMuonPtThreshold(const double& threshold);
	void SetElectronChannelPhotonPtThreshold(const double& threshold);
	void SetMuonChannelPhotonPtThreshold(const double& threshold);
	void SetElectronChannelPhotonEtaRestriction(const double& threshold);
	void SetMuonChannelPhotonEtaRestriction(const double& threshold);
	void SetPhotonPtOverMassThreshold(const double& threshold);
	void SetPhotonIdentificationWP(const int& wp);
	void SetPhotonVetoElectron(const int& veto);
	void SetElectronChannelTriggers(const std::vector<TString>& triggers);
	void SetMuonChannelTriggers(const std::vector<TString>& triggers);
	void SetOutputPath(const TString& output_path);
private:
	std::pair<std::vector<TLorentzVector>, bool> SelectElectrons(const Event&);
	std::pair<std::vector<TLorentzVector>, bool> SelectMuons(const Event&);
	std::pair<std::vector<TLorentzVector>, bool> SelectPhotons(const Event& event, const std::vector<TLorentzVector> leptons);
	void FillGenPhotonPt(const Event& event);
	bool IsPromptPhoton(const TLorentzVector&, const Event&);
	double DeltaR(const std::pair<double, double>& eta1_phi1, const std::pair<double, double>& eta2_phi2);

	const bool _is_mc;
	const bool _is_zg;
	const bool _is_dy;
	double _eeg_leading_pt_cut;
	double _eeg_subleading_pt_cut;
	double _eeg_pho_pt_cut;
	double _eeg_pho_eta_cut;
	double _mmg_leading_pt_cut;
	double _mmg_subleading_pt_cut;
	double _mmg_pho_pt_cut;
	double _mmg_pho_eta_cut;
	double _pho_pt_over_llg_mass_cut;
	int _pho_mva_wp;
	int _pho_veto_el;
	std::vector<TString> _eeg_triggers;
	std::vector<TString> _mmg_triggers;
	TString _output_path;

	// TLorentzVector _leading_lepton;
	// TLorentzVector _subleading_lepton;
	// TLorentzVector _photon;
	double _lepton0_pt;
	double _lepton0_eta;
	double _lepton0_phi;
	double _lepton1_pt;
	double _lepton1_eta;
	double _lepton1_phi;
	double _photon_pt;
	double _photon_eta;
	double _photon_phi;
	double _m_llg;
	double _gen_weight;
	double _gen_photon_pt;

	TTree _eeg_events;
	TTree _mmg_events;
};

#endif