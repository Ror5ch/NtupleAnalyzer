#include "event/Event.h"

void Event::SetRunNumber(const int& run_number)
{
    _run_number = run_number;
}
void Event::SetLS(const int& ls)
{
    _ls = ls;
}
void Event::SetEventNumber(const unsigned long long& event_number)
{
    _event_number = event_number;
}
void Event::SetNumVertices(const int& num_vertices)
{
    _num_vertices = num_vertices;
}
void Event::SetNumPU(const int& num_pu)
{
    _num_pu = num_pu;
}
void Event::SetWeight(const double& weight)
{
    _weight = weight;
}
void Event::SetFilterResults(std::vector<TriggerResult>&& filters)
{
    _filters = std::move(filters);
}
void Event::SetTriggerResults(std::vector<TriggerResult>&& triggers)
{
    _triggers = std::move(triggers);
}
void Event::SetElectrons(std::vector<Electron>&& electrons)
{
    _electrons = std::move(electrons);
}
void Event::SetMuons(std::vector<Muon>&& muons)
{
    _muons = std::move(muons);
}
void Event::SetPhotons(std::vector<Photon>&& photons)
{
    _photons = std::move(photons);
}
void Event::SetGenParticles(std::vector<GenParticle>&& gen_particles)
{
    _gen_particles = std::move(gen_particles);
}
void Event::SetProtons(std::vector<Proton>&& protons)
{
    _protons = std::move(protons);
}
void Event::SetLocalTracks(std::vector<LocalTrack>&& local_tracks)
{
    _local_tracks = std::move(local_tracks);
}
const int& Event::RunNumber() const
{
    return _run_number;
}
const int& Event::LS() const
{
    return _ls;
}
const unsigned long long& Event::EventNumber() const
{
    return _event_number;
}
const int& Event::NumVertices() const
{
    return _num_vertices;
}
const int& Event::NumPU() const
{
    return _num_pu;
}
const double& Event::Weight() const
{
    return _weight;
}
bool Event::IsFiltered(const TString& filter_name) const
{
    bool decision = false;
    for (const auto& _filter : _filters)
    {
        const auto& _filter_name = _filter.Name();
        if (_filter_name.Contains(filter_name))
        {
            decision = _filter.Decision();
            break;
        }
    }
    return decision;
}
bool Event::IsTriggered(const TString& trigger_name) const
{
    bool decision = false;
    for (const auto& _trigger : _triggers)
    {
        const auto& _trigger_name = _trigger.Name();
        if (_trigger_name.Contains(trigger_name))
        {
            decision = _trigger.Decision();
            break;
        }
    }
    return decision;
}
const std::vector<Electron>& Event::Electrons() const
{
    return _electrons;
}
const std::vector<Muon>& Event::Muons() const
{
    return _muons;
}
const std::vector<Photon>& Event::Photons() const
{
    return _photons;
}
const std::vector<Proton>& Event::Protons() const
{
    return _protons;
}
const std::vector<LocalTrack>& Event::LocalTracks() const
{
    return _local_tracks;
}
const std::vector<GenParticle>& Event::GenParticles() const
{
    return _gen_particles;
}