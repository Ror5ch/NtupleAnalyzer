#ifndef _MAKEANALYZER_
#define _MAKEANALYZER_

#include "analyzer/EventAnalyzer.h"
#include "analyzer/JobConfiguration.h"
#include "analyzer/ZGSelector.h"

std::unique_ptr<EventAnalyzer> MakeAnalyzer(const JobConfiguration& conf);

#endif