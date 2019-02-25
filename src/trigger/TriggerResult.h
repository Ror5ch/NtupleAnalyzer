#ifndef _TRIGGERRESULT_
#define _TRIGGERRESULT_

#include <string>

#include "TString.h"

class TriggerResult
{
public:
	TriggerResult() = delete;
	TriggerResult(const std::string& name, const bool& decision);
	~TriggerResult() {};
	const TString& Name() const;
	const bool& Decision() const;
private:
	const TString _name;
	const bool _decision;
};

#endif