#include "analyzer/EventAnalyzer.h"

EventAnalyzer::EventAnalyzer(std::unique_ptr<EventHandle> event_handle, std::unique_ptr<EventSelector> event_selector)
: _event_handle{std::move(event_handle)}, _event_selector{std::move(event_selector)}
{
    _event_handle->SetBranchStatus();
}

void EventAnalyzer::Analyze()
{
    const auto entries = _event_handle->NumberOfEvents();
    for (auto entry = 0; entry < entries; ++entry)
    {
        const auto& event = _event_handle->GetEvent(entry);
        _event_selector->Select(event);
    }
}
void EventAnalyzer::Save()
{
    _event_selector->Save();
}