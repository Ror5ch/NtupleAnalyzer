#include "particle/Photon.h"

const double Photon::MASS = 0.;

Photon::Photon(const double& pt, const double& eta, const double& phi, const bool& mva_wp80, const bool& mva_wp90, const bool& pass_conversion_veto, const bool& has_pixel_seed)
: Particle{pt, eta, phi, Photon::MASS}, _mva_result{{80, mva_wp80}, {90, mva_wp90}}, _pass_conversion_veto{pass_conversion_veto}, _has_pixel_seed{has_pixel_seed} 
{
}
bool Photon::PassAcceptance(const double& pt_cut, const double& eta_cut) const
{
	return Particle::PassAcceptance(pt_cut, eta_cut) && NotInTransitionRegion();
}
bool Photon::PassIdentification(const int& wp) const
{
	return _mva_result.at(wp);
}
bool Photon::NotInTransitionRegion() const
{
	const auto& abseta = fabs(Eta());
	return abseta < 1.4442 || abseta > 1.566;
}
bool Photon::PassVeto(const int& num) const
{
    if (num == 0) return _pass_conversion_veto;
    else return !_has_pixel_seed;
}