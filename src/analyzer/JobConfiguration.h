#ifndef _JOBCONFIGURATION_
#define _JOBCONFIGURATION_

#include <iostream>

#include "TObjArray.h"
#include "TObjString.h"
#include "TString.h"

class JobConfiguration
{
public:
    JobConfiguration() = delete;
    JobConfiguration(int argc, char *argv[]);

    TString job_type;
    bool is_mc;
    bool is_zg;
    bool is_dy;
    std::vector<TString> input_file_locations;
    TString output_file_location;
    std::vector<TString> eeg_triggers;
    std::vector<TString> mmg_triggers;
    std::vector<double> thresholds;
private:
    bool GetBool(char* decision_char);
    int GetFileNumber(char* number_char);
    std::vector<TString> GetFileLocations(char* file_directory_char, char* first_file_number_char, char* last_file_number_char);
    std::vector<TString> ReadTriggers(char* trigger_names);
    std::vector<double> ReadThresholds(char* threshold_values);
};

#endif