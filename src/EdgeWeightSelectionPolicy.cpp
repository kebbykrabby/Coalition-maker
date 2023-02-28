#include "SelectionPolicy.h"

#include <iostream>
using std::cout;
using std::endl;

Party EdgeWeightSelectionPolicy:: select(int partyId, Simulation *sim, int coalitionId)
{
    Graph g = sim->getGraph();
    vector<Party> options = g.getNeighbors(partyId);
    vector<int> weights = g.getNeighborsWeight(partyId , options);
    JoinPolicy *jp;
    jp = new MandatesJoinPolicy;
    Party maxWeightParty  = Party(-1,"temp",0,jp);
    int maxWeight = 0;
    for(unsigned int i = 0; i < weights.size(); i++)
    {
        int currWeight = weights.at(i);
        if ((currWeight > maxWeight) & (options.at(i).getState()!=Joined))
        {
            vector<Coalition> currOffers = options.at(i).getOffers();
            bool gotOffer = false;
            for (unsigned int j = 0; j<currOffers.size(); j++)
            {
                if (currOffers.at(j).getId() == coalitionId)
                    {
                        gotOffer = true;    
                    }
            }
            if (!gotOffer)
            {
                maxWeightParty = options.at(i);
                maxWeight = currWeight;
            }
        }
    }
    return maxWeightParty;
}
char EdgeWeightSelectionPolicy::getType()
{
    return 'E';
}
