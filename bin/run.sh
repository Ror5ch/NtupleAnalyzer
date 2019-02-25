input_location="RunIISummer16MiniAODv2/GluGluSpin0ToZG_ZToLL_W-5p6_M-300_TuneCUEP8M1_13TeV-pythia8"
first_file_num=1
last_file_num=1
output_location="output/W-5p6_M-300.root"
log_location="log/W-5p6_M-300"

./Analyze ZG True False False ${input_location} ${first_file_num} ${last_file_num} ${output_location} HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v "HLT_IsoMu24_v:HLT_IsoTkMu24_v" 25:15:25:2.5:26:10:25:2.5:0.192:80:0 > ${log_location}
