#pragma once

#include <vector>
#include "Graph.h"

using std::vector;
class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    Agent(const Agent& other);
    Agent(Agent&& other) noexcept;
    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    void setPartyId(int id);
    void setAgentId(int id);
    int getCoalitionId() const;
    ~Agent();
    Agent &operator =(const Agent &other);
    Agent& operator=(Agent&& other) noexcept;


private:
    int mAgentId;
    int mPartyId;
    

    SelectionPolicy *mSelectionPolicy;
    int mCoalitionId;
};
