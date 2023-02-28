#include "Agent.h"
#include "SelectionPolicy.h"

#include <iostream>
using std::cout;
using std::endl;

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy),mCoalitionId(mAgentId)
{
    // You can change the implementation of the constructor, but not the signature!
    

}

Agent::Agent(const Agent& other) : mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(), mCoalitionId(other.mCoalitionId)
{
    char type = other.mSelectionPolicy->getType();
    if (type == 'M')
    {
        mSelectionPolicy = new MandatesSelectionPolicy();
    }
    else
    {
        mSelectionPolicy = new EdgeWeightSelectionPolicy();
    }
}
Agent::Agent(Agent&& other) noexcept: mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy), mCoalitionId(other.mCoalitionId)
{
    other.mSelectionPolicy = nullptr;
}

void Agent::setPartyId(int id)
{
    mPartyId = id;
}

void Agent:: setAgentId(int id)
{
    mAgentId = id;
}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

int Agent::getCoalitionId() const
{
    return mCoalitionId;
}



void Agent::step(Simulation &sim)
{
    // TODO: implement this method
    Party newOffer = mSelectionPolicy->select(mPartyId, &sim, mCoalitionId);
    if (newOffer.getId() != -1)
    {
        newOffer.addOffer(sim.getCoalitionById(mCoalitionId));    
    }
    
}


Agent:: ~Agent()
{ 
    delete mSelectionPolicy;
}

Agent&Agent::operator =(const Agent &other)
{
    if (this!= &other)
    {
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mCoalitionId = other.mCoalitionId;
        char type = other.mSelectionPolicy->getType();
        if (type == 'M')
        {
            mSelectionPolicy = new MandatesSelectionPolicy();
        }
        else
        {
            mSelectionPolicy = new EdgeWeightSelectionPolicy();
        }
    }
    return *this;
}

Agent& Agent:: operator=(Agent&& other) noexcept
{
    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    mSelectionPolicy = other.mSelectionPolicy;
    mCoalitionId = other.mCoalitionId;

    other.mSelectionPolicy = nullptr;

    return *this;
}