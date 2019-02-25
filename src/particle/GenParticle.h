#ifndef _GENPARTICLE_
#define _GENPARTICLE_

#include "particle/Particle.h"

class GenParticle : public Particle
{
public:
	GenParticle() = delete;
	GenParticle(const double& pt, const double& eta, const double& phi, const double& mass, const int& charge, const int& id,
	const bool& fromHardProcessFinalState, const bool& isHardProcess, const bool& isPromptFinalState);
	~GenParticle() {};
	const int& Charge() const;
	const int& ID() const;
	const bool& FromHardProcessFinalState() const;
	const bool& IsHardProcess() const;
	const bool& IsPromptFinalState() const;
private:
	const int _charge;
	const int _id;
	const bool _from_hard_process_final_state;
	const bool _is_hard_process;
	const bool _is_prompt_final_state;
};

#endif