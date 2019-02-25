#include "analyzer/MakeAnalyzer.h"

std::unique_ptr<EventAnalyzer> MakeAnalyzer(const JobConfiguration& conf)
{
    auto event_handle = std::make_unique<EventHandle>(conf.input_file_locations, conf.is_mc);
    std::unique_ptr<EventSelector> event_selector{nullptr};

    auto zg_selector = new ZGSelector(conf.is_mc, conf.is_zg, conf.is_dy);
    zg_selector->SetOutputPath(conf.output_file_location);
    zg_selector->SetElectronChannelTriggers(conf.eeg_triggers);
    zg_selector->SetMuonChannelTriggers(conf.mmg_triggers);
    zg_selector->SetLeadingElectronPtThreshold(conf.thresholds[0]);
    zg_selector->SetSubleadingElectronPtThreshold(conf.thresholds[1]);
    zg_selector->SetElectronChannelPhotonPtThreshold(conf.thresholds[2]);
    zg_selector->SetElectronChannelPhotonEtaRestriction(conf.thresholds[3]);
    zg_selector->SetLeadingMuonPtThreshold(conf.thresholds[4]);
    zg_selector->SetSubleadingMuonPtThreshold(conf.thresholds[5]);
    zg_selector->SetMuonChannelPhotonPtThreshold(conf.thresholds[6]);
    zg_selector->SetMuonChannelPhotonEtaRestriction(conf.thresholds[7]);
    zg_selector->SetPhotonPtOverMassThreshold(conf.thresholds[8]);
    zg_selector->SetPhotonIdentificationWP(conf.thresholds[9]);
    zg_selector->SetPhotonVetoElectron(conf.thresholds[10]);
    event_selector.reset(zg_selector);

    auto event_analyzer = std::make_unique<EventAnalyzer>(std::move(event_handle), std::move(event_selector));
    return event_analyzer;
}