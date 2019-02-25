#ifndef _EVENTANALYZER_
#define _EVENTANALYZER_

#include <iostream>

#include "event/EventHandle.h"
#include "analyzer/EventSelector.h"

class EventAnalyzer
{
public:
	EventAnalyzer() = delete;
	EventAnalyzer(std::unique_ptr<EventHandle>, std::unique_ptr<EventSelector>);
	~EventAnalyzer() {};
	void Analyze();
	void Save();
private:
	std::unique_ptr<EventHandle> _event_handle;
	std::unique_ptr<EventSelector> _event_selector;
};

#endif