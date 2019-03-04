ifeq ($(HOSTNAME), tamsa2)
	CXX = /cvmfs/cms.cern.ch/slc6_amd64_gcc530/external/gcc/5.3.0/bin/g++ -pthread -std=c++14 -m64 -I. -I/opt/ohpc/pub/apps/root_6_12_06/include -L/opt/ohpc/pub/apps/root_6_12_06/lib -lGui -lCore -lImt -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lTreePlayer -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -lMultiProc -pthread -lm -ldl -rdynamic -D"_NOTCMSSW_=DEFINITELY"
else
	CXX = c++ -pthread -stdlib=libc++ -std=c++14 -m64 -I. -I/Users/knam/ROOT/include -L/Users/knam/ROOT/lib -lGui -lCore -lImt -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lROOTVecOps -lTree -lTreePlayer -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -lMultiProc -lROOTDataFrame -lpthread -stdlib=libc++ -lm -ldl -D"_NOTCMSSW_=DEFINITELY"
endif

TARGET = ../bin/Analyze

$(TARGET) : Particle.o Electron.o Muon.o Photon.o Proton.o LocalTrack.o GenParticle.o TriggerResult.o Event.o EventBuffer.o EventHandle.o EventSelector.o ZGSelector.o RoccoR.o EventAnalyzer.o MakeAnalyzer.o JobConfiguration.o Main.o
	$(CXX) -o $(TARGET) Particle.o Electron.o Muon.o Photon.o Proton.o LocalTrack.o GenParticle.o TriggerResult.o Event.o EventBuffer.o EventHandle.o EventSelector.o ZGSelector.o RoccoR.o EventAnalyzer.o MakeAnalyzer.o JobConfiguration.o Main.o

Particle.o : particle/Particle.cc particle/Particle.h
	$(CXX) -c -o Particle.o particle/Particle.cc

Electron.o : particle/Electron.cc particle/Electron.h
	$(CXX) -c -o Electron.o particle/Electron.cc

Muon.o : particle/Muon.cc particle/Muon.h
	$(CXX) -c -o Muon.o particle/Muon.cc

Photon.o : particle/Photon.cc particle/Photon.h
	$(CXX) -c -o Photon.o particle/Photon.cc

Proton.o : particle/Proton.cc particle/Proton.h
	$(CXX) -c -o Proton.o particle/Proton.cc

LocalTrack.o : particle/LocalTrack.cc particle/LocalTrack.h
	$(CXX) -c -o LocalTrack.o particle/LocalTrack.cc

GenParticle.o : particle/GenParticle.cc particle/GenParticle.h
	$(CXX) -c -o GenParticle.o particle/GenParticle.cc

TriggerResult.o : trigger/TriggerResult.cc trigger/TriggerResult.h
	$(CXX) -c -o TriggerResult.o trigger/TriggerResult.cc

Event.o : event/Event.cc event/Event.h
	$(CXX) -c -o Event.o event/Event.cc

EventBuffer.o : event/EventBuffer.cc event/EventBuffer.h
	$(CXX) -c -o EventBuffer.o event/EventBuffer.cc

RoccoR.o : etc/RoccoR.cc etc/RoccoR.h
	$(CXX) -c -o RoccoR.o etc/RoccoR.cc

EventHandle.o : event/EventHandle.cc event/EventHandle.h
	$(CXX) -c -o EventHandle.o event/EventHandle.cc

EventSelector.o : analyzer/EventSelector.cc analyzer/EventSelector.h
	$(CXX) -c -o EventSelector.o analyzer/EventSelector.cc

ZGSelector.o : analyzer/ZGSelector.cc analyzer/ZGSelector.h
	$(CXX) -c -o ZGSelector.o analyzer/ZGSelector.cc

EventAnalyzer.o : analyzer/EventAnalyzer.cc analyzer/EventAnalyzer.h
	$(CXX) -c -o EventAnalyzer.o analyzer/EventAnalyzer.cc

MakeAnalyzer.o : analyzer/MakeAnalyzer.cc analyzer/MakeAnalyzer.h
	$(CXX) -c -o MakeAnalyzer.o analyzer/MakeAnalyzer.cc

JobConfiguration.o : analyzer/JobConfiguration.cc analyzer/JobConfiguration.h
	$(CXX) -c -o JobConfiguration.o analyzer/JobConfiguration.cc

Main.o : app/Main.cc
	$(CXX) -c -o Main.o app/Main.cc

clean:
	rm *.o
