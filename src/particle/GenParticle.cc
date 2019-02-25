#include "particle/GenParticle.h"

GenParticle::GenParticle(const double& pt, const double& eta, const double& phi, const double& mass, const int& charge, const int& id,
const bool& fromHardProcessFinalState, const bool& isHardProcess, const bool& isPromptFinalState)
: Particle{pt, eta, phi, mass}, _charge{charge}, _id{id}, _from_hard_process_final_state{fromHardProcessFinalState}, _is_hard_process{isHardProcess}, _is_prompt_final_state{isPromptFinalState}
{
}

const int& GenParticle::Charge() const
{
	return _charge;
}

const int& GenParticle::ID() const
{
	return _id;
}

const bool& GenParticle::FromHardProcessFinalState() const
{
	return _from_hard_process_final_state;
}

const bool& GenParticle::IsHardProcess() const
{
	return _is_hard_process;
}

const bool& GenParticle::IsPromptFinalState() const
{
	return _is_prompt_final_state;
}