#include "SelectionPolicy.h"

Party MandatesSelectionPolicy::select(int partyId, Simulation *sim, int coalitionId)
{

    Graph g = sim->getGraph();
    vector<Party> options = g.getNeighbors(partyId);
    JoinPolicy *jp;
    jp = new MandatesJoinPolicy;
    Party maxMand = Party(-1,"temp", 0, jp);
    int numOfMand = maxMand.getMandates();
    for (unsigned int i = 0; i < options.size(); i++)
    {
        int currMand = options.at(i).getMandates();
        if( (currMand > numOfMand) & (options.at(i).getState()!=Joined))
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
                maxMand = options.at(i);
                numOfMand = currMand;
            }
            
        }
    }
    return maxMand;
}

char MandatesSelectionPolicy::getType()
{
    return 'M';
}
