#include "particle/Muon.h"

const double Muon::MASS = 0.1056583715;

Muon::Muon(const double& pt, const double& eta, const double& phi, const bool& is_pf_muon, const bool& is_global_muon, const bool& is_tracker_muon,
const int& valid_muon_hits, const int& valid_pixel_hits, const int& tracker_layers, const int& matched_stations,
const double& dxy_vtx, const double& dz_vtx, const double& best_pt, const double& best_pt_error, const double& tracker_iso)
: Particle{pt, eta, phi, Muon::MASS}, _is_pf_muon{is_pf_muon}, _is_global_muon{is_global_muon}, _is_tracker_muon{is_tracker_muon},
_valid_muon_hits{valid_muon_hits}, _valid_pixel_hits{valid_pixel_hits}, _tracker_layers{tracker_layers}, _matched_stations{matched_stations},
_dxy_vtx{dxy_vtx}, _dz_vtx{dz_vtx}, _best_pt{best_pt}, _best_pt_error{best_pt_error}, _tracker_iso{tracker_iso}
{
}

bool Muon::PassIdentification() const
{
    return (_is_pf_muon && (_is_global_muon||_is_tracker_muon) && fabs(_dxy_vtx) < 0.2 && fabs(_dz_vtx) < 0.5) && PassTrackerIsolation();
}

bool Muon::PassHighPtIdentification() const
{
        return (_is_global_muon && _is_tracker_muon && _valid_muon_hits > 0 && _matched_stations > 1
                  && _valid_pixel_hits > 0
                  && _tracker_layers > 5
                  && _dxy_vtx < 0.2
                  && _best_pt_error/ _best_pt < 0.3) && PassTrackerIsolation();
}

bool Muon::PassTrackerIsolation() const
{
	return _tracker_iso / Pt() < 0.1;
}