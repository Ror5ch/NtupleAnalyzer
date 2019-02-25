#ifndef _MUON_
#define _MUON_

#include "particle/Particle.h"

class Muon : public Particle
{
public:
	const static double MASS; 
	Muon() = delete;
	Muon(const double& pt, const double& eta, const double& phi, const bool& is_pf_muon, const bool& is_global_muon, const bool& is_tracker_muon,
	const int& valid_muon_hits, const int& valid_pixel_hits, const int& tracker_layers, const int& matched_stations,
	const double& dxy_vtx, const double& dz_vtx, const double& best_pt, const double& best_pt_error, const double& tracker_iso);
	~Muon() {};
	virtual bool PassIdentification() const;
	bool PassHighPtIdentification() const;
private:
	bool PassTrackerIsolation() const;
	const bool _is_pf_muon;
	const bool _is_global_muon;
	const bool _is_tracker_muon;
	const int _valid_muon_hits;
	const int _valid_pixel_hits;
	const int _tracker_layers;
	const int _matched_stations;
	const double _dxy_vtx;
	const double _dz_vtx;
	const double _best_pt;
	const double _best_pt_error;
	const double _tracker_iso;
};

#endif