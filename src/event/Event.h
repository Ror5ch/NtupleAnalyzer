#ifndef _EVENT_
#define _EVENT_

#include <iostream>

#include "TString.h"

#include "particle/Electron.h"
#include "particle/Muon.h"
#include "particle/Photon.h"
#include "particle/Proton.h"
#include "particle/LocalTrack.h"
#include "particle/GenParticle.h"
#include "trigger/TriggerResult.h"

class Event
{
public:
    Event() {};
    ~Event() {};

    void SetRunNumber(const int& run_number);
    void SetLS(const int& ls);
    void SetEventNumber(const unsigned long long& event_number);
    void SetNumVertices(const int& num_vertices);
    void SetNumPU(const int& num_pu);
    void SetWeight(const double& weight);
    void SetFilterResults(std::vector<TriggerResult>&& filters);
    void SetTriggerResults(std::vector<TriggerResult>&& triggers);
    void SetElectrons(std::vector<Electron>&& electrons);
    void SetMuons(std::vector<Muon>&& muons);
    void SetPhotons(std::vector<Photon>&& photons);
    void SetProtons(std::vector<Proton>&& protons);
    void SetLocalTracks(std::vector<LocalTrack>&& local_tracks);
    void SetGenParticles(std::vector<GenParticle>&& gen_particles);

    const int& RunNumber() const;
    const int& LS() const;
    const unsigned long long& EventNumber() const;
    const int& NumVertices() const;
    const int& NumPU() const;
    const double& Weight() const;
    bool IsFiltered(const TString& filter_name) const;
    bool IsTriggered(const TString& trigger_name) const;
    const std::vector<Electron>& Electrons() const;
    const std::vector<Muon>& Muons() const;
    const std::vector<Photon>& Photons() const;
    const std::vector<Proton>& Protons() const;
    const std::vector<LocalTrack>& LocalTracks() const;
    const std::vector<GenParticle>& GenParticles() const;
private:
    int _run_number;
    int _ls;
    unsigned long long _event_number;
    int _num_vertices;
    int _num_pu;
    double _weight;
    std::vector<TriggerResult> _filters;
    std::vector<TriggerResult> _triggers;
    std::vector<Electron> _electrons;
    std::vector<Muon> _muons;
    std::vector<Photon> _photons;
    std::vector<Proton> _protons;
    std::vector<LocalTrack> _local_tracks;
    std::vector<GenParticle> _gen_particles;
};

#endif