#ifndef _EVENTSELECTOR_
#define _EVENTSELECTOR_

#include "event/Event.h"

class EventSelector
{
public:
	EventSelector() {};
	~EventSelector() {};
	virtual void Select(const Event&);
	virtual void Save();
};

#endif