#pragma once
#include <vector>
#include "Party.h"

using std::vector;

class Graph
{
public:
    Graph(vector<Party> vertices, vector<vector<int>> edges);
    int getMandates(int partyId) const;
    int getEdgeWeight(int v1, int v2) const;
    int getNumVertices() const;
    const Party &getParty(int partyId) const;
    Party getPartyNotConst(int partyId); //new
    vector<Party> getParties();

    vector<Party> getNeighbors(int partyId);
    vector<int> getNeighborsWeight(int partyId, vector<Party> neighbors);
    
private:
    vector<Party> mVertices;
    vector<vector<int>> mEdges;
};
