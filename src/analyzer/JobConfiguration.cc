#include "analyzer/JobConfiguration.h"

JobConfiguration::JobConfiguration(int argc, char *argv[])
{
    assert(argc == 12);

    job_type = argv[1]; 
    is_mc = GetBool(argv[2]);
    is_zg = GetBool(argv[3]);
    is_dy = GetBool(argv[4]);
    input_file_locations = GetFileLocations(argv[5], argv[6], argv[7]);
    output_file_location = argv[8];
    eeg_triggers = ReadTriggers(argv[9]);
    mmg_triggers = ReadTriggers(argv[10]);
    thresholds = ReadThresholds(argv[11]);
}

bool JobConfiguration::GetBool(char* decision_char)
{
    TString decision{decision_char};
    return (decision == "True");
}

int JobConfiguration::GetFileNumber(char* number_char)
{
    TString number_string{number_char};
    return number_string.Atoi();
}

std::vector<TString> JobConfiguration::GetFileLocations(char* file_directory_char, char* first_file_number_char, char* last_file_number_char)
{
    TString file_directory{file_directory_char};
    std::vector<TString> file_locations{};
    int first_file_number{GetFileNumber(first_file_number_char)};
    int last_file_number{GetFileNumber(last_file_number_char)};

    // std::cout << "From " << first_input_file_number << " to " << last_input_file_number << std::endl;
    for (auto i = first_file_number; i <= last_file_number; ++i)
    {
        file_locations.push_back(file_directory + "/ntuple_" + TString::Itoa(i, 10) + ".root");
    }
    return file_locations;
}

std::vector<TString> JobConfiguration::ReadTriggers(char* trigger_names)
{
    TString trigger_list{trigger_names};
    auto tokens = trigger_list.Tokenize(":");
    std::vector<TString> triggers{};
    for (auto i = 0; i < tokens->GetEntries(); ++i)
    {
        auto trigger = (static_cast<TObjString*>(tokens->At(i)))->GetString();
        triggers.push_back(trigger);
    }
    return triggers;
}

std::vector<double> JobConfiguration::ReadThresholds(char* threshold_values)
{
    TString threshold_list{threshold_values};
    auto tokens = threshold_list.Tokenize(":");
    std::vector<double> thresholds{};
    for (auto i = 0; i < tokens->GetEntries(); ++i)
    {
        auto threshold = ((static_cast<TObjString*>(tokens->At(i)))->GetString()).Atof();
        // auto threshold = ((static_cast<TObjString*>(tokens->At(i)))->GetString()).Atoi();
        thresholds.push_back(threshold);
    }
    return thresholds;
}