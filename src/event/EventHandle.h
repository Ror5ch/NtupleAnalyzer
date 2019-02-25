#ifndef _EVENTHANDLE_
#define _EVENTHANDLE_

#include <iostream>

#include "TChain.h"

#include "event/Event.h"
#include "event/EventBuffer.h"
#include "etc/RoccoR.h"

class EventHandle
{
public:
	EventHandle(const std::vector<TString>&, const bool&);
	~EventHandle() {};
	void SetBranchStatus();
	const Event& GetEvent(const int& entry_number);
	int NumberOfEvents() const;
private:
	void ReconstructEventFromBuffer();
	void MuonMomentumCorrection();
	const bool _is_mc; 
	TChain* _data;
	EventBuffer _buffer;
	Event _event;
	RoccoR _corrector;
};

#endif