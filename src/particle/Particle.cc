#include "particle/Particle.h"

Particle::Particle(const double& pt, const double& eta, const double& phi, const double& mass): _pt{pt}, _eta{eta}, _phi{phi}, _mass{mass}
{
}

const double& Particle::Pt() const
{
	return _pt;
}

const double& Particle::Eta() const
{
	return _eta;
}

const double& Particle::Phi() const
{
	return _phi;
}

const double& Particle::Mass() const
{
	return _mass;
}

bool Particle::PassAcceptance(const double& pt_cut, const double& eta_cut) const
{
	return _pt > pt_cut && fabs(_eta) < eta_cut;
}

TLorentzVector Particle::FourMomentum() const
{
	TLorentzVector momentum;
	momentum.SetPtEtaPhiM(_pt, _eta, _phi, _mass);
	return momentum;
}

bool Particle::PassIdentification() const
{
	return true;
}