#include "Simulation.h"

#include <iostream>
using std::cout;
using std::endl;


Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) ,mCoalitions(),mParties()
{
    for (Agent currAgent:mAgents)
    {
        // Agent currAgent = mAgents.at(i);
        int coalitionId = currAgent.getCoalitionId();
        Coalition co = Coalition(coalitionId);
        // int partyId = (currAgent).getPartyId();
        int mandates = mGraph.getMandates((currAgent).getPartyId());
        co.addMandates(mandates);
        co.addAgent(currAgent.getId());
       
        mCoalitions.push_back(co);
    }
    mParties = mGraph.getParties();
    
    // You can change the implementation of the constructor, but not the signature!
}

void Simulation::step()
{
    // TODO: implement this method
    
    for(Party party:mParties)
    {
        party.step(*this);
    }
    for(Agent agent:mAgents)
    {
        agent.step(*this);  
    }
}

bool Simulation::shouldTerminate() const
{
    // TODO implement this method
    for(unsigned int i=0;i<mCoalitions.size();i++)
    {
        if(mCoalitions.at(i).getMandates()>=61)
        {
            return true;
        }
    }
    for (unsigned int i=0;i<mParties.size();i++)
    {
        if (mParties.at(i).getState()!=Joined)
        {
            return false;
        }
    } 
    return true;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

const Coalition Simulation::getCoalitionById(int CoalitionId) const
{
    return mCoalitions.at(CoalitionId);
}

void Simulation::addAgent(Agent newAgent)
{
    mAgents.push_back(newAgent);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    vector<vector<int>> partiesByCoalitions;
    for(unsigned int i=0; i< mCoalitions.size();i++)
    {
        vector<int>parties = mCoalitions.at(i).getParties();
        for(unsigned int j=0; j< parties.size(); i++)
        {
            partiesByCoalitions.at(i).push_back(parties.at(j));
        }
    }
    return partiesByCoalitions;
}
