#ifndef _PARTICLE_
#define _PARTICLE_

#include "TLorentzVector.h"

class Particle
{
public:
	Particle() = delete;
	Particle(const double& pt, const double& eta, const double& phi, const double& mass);
	~Particle() {};
	TLorentzVector FourMomentum() const;
	const double& Pt() const;
	const double& Eta() const;
	const double& Phi() const;
	const double& Mass() const;
	virtual bool PassAcceptance(const double& pt_cut, const double& eta_cut) const;
	virtual bool PassIdentification() const;
private:
	const double _pt;
	const double _eta;
	const double _phi;
	const double _mass;
};

#endif