#include "trigger/TriggerResult.h"

TriggerResult::TriggerResult(const std::string& name, const bool& decision): _name{name}, _decision{decision}
{
}
const TString& TriggerResult::Name() const
{
	return _name;
}
const bool& TriggerResult::Decision() const
{
	return _decision;
}