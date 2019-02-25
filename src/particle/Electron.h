#ifndef _ELECTRON_
#define _ELECTRON_

#include "particle/Particle.h"

class Electron : public Particle
{
public:
	const static double MASS;
	Electron() = delete;
	Electron(const double& pt, const double& eta, const double& phi, const bool& pass_official_vid, const double& sigma_ietaieta,
	const double& deta_in_seed, const double& dphi_in, const double& h_over_e, const double& pf_iso, const double& ooe_minus_oop,
	const int& missing_hits, const bool& pass_conversion_veto, const double& mini_iso);
	~Electron() {};
	virtual bool PassAcceptance(const double& pt_cut, const double& eta_cut) const;
	virtual bool PassIdentification() const;
	const double& SigmaIetaIeta() const;
	const double& DetaInSeed() const;
	const double& DphiIn() const;
	const double& HoverE() const;
	const double& PFIso() const;
	const double& OoeMinusOop() const;
	const int& MissingHits() const;
	const bool& PassConversionVeto() const;
	const double& MiniIso() const;
private:
	bool NotInTransitionRegion() const;
	const bool _pass_official_vid;
	const double _sigma_ietaieta;
	const double _deta_in_seed;
	const double _dphi_in;
	const double _h_over_e;
	const double _pf_iso;
	const double _ooe_minus_oop;
	const int _missing_hits;
	const bool _pass_conversion_veto;
	const double _mini_iso;
};

#endif