#ifndef _PHOTON_
#define _PHOTON_

#include <map>

#include "particle/Particle.h"

class Photon : public Particle
{
public:
	const static double MASS;
	Photon() = delete;
	Photon(const double& pt, const double& eta, const double& phi, const bool& mva_wp80, const bool& mva_wp90, const bool& pass_conversion_veto, const bool& has_pixel_seed);
	~Photon() {};
	virtual bool PassAcceptance(const double& pt_cut, const double& eta_cut) const;
    virtual bool PassIdentification(const int& wp = 90) const;
	virtual bool PassVeto(const int& num = 0) const;
private:
	bool NotInTransitionRegion() const;
    const std::map<int, bool> _mva_result;
	const bool _pass_conversion_veto;
	const bool _has_pixel_seed;
};

#endif