#include "particle/Electron.h"

const double Electron::MASS = 0.000510998;

Electron::Electron(const double& pt, const double& eta, const double& phi, const bool& pass_official_vid, const double& sigma_ietaieta,
	const double& deta_in_seed, const double& dphi_in, const double& h_over_e, const double& pf_iso, const double& ooe_minus_oop,
	const int& missing_hits, const bool& pass_conversion_veto, const double& mini_iso)
: Particle{pt, eta, phi, Electron::MASS}, _pass_official_vid{pass_official_vid}, _sigma_ietaieta{sigma_ietaieta},
_deta_in_seed{deta_in_seed}, _dphi_in{dphi_in}, _h_over_e{h_over_e}, _pf_iso{pf_iso}, _ooe_minus_oop{ooe_minus_oop},
_missing_hits{missing_hits}, _pass_conversion_veto{pass_conversion_veto}, _mini_iso{mini_iso}
{
}
bool Electron::PassAcceptance(const double& pt_cut, const double& eta_cut) const
{
	return Particle::PassAcceptance(pt_cut, eta_cut) && NotInTransitionRegion();
}
bool Electron::PassIdentification() const
{
	return _pass_official_vid;
}
bool Electron::NotInTransitionRegion() const
{
	const auto abseta = fabs(Eta());
	return abseta < 1.4442 || abseta > 1.566;
}
const double& Electron::SigmaIetaIeta() const
{
	return _sigma_ietaieta;
}
const double& Electron::DetaInSeed() const
{
	return _deta_in_seed;
}
const double& Electron::DphiIn() const
{
	return _dphi_in;
}

const double& Electron::HoverE() const
{
	return _h_over_e;
}
const double& Electron::PFIso() const
{
	return _pf_iso;
}
const double& Electron::OoeMinusOop() const
{
	return _ooe_minus_oop;
}
const int& Electron::MissingHits() const
{
	return _missing_hits;
}
const bool& Electron::PassConversionVeto() const
{
	return _pass_conversion_veto;
}
const double& Electron::MiniIso() const
{
	return _mini_iso;
}