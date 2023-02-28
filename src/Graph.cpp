#include "Graph.h"



Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges) 
{
    // You can change the implementation of the constructor, but not the signature!
}  
int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}

int Graph::getNumVertices() const
{
    return mVertices.size();
}

const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}

Party Graph::getPartyNotConst(int partyId)
{
    return mVertices[partyId];
}


vector<Party> Graph::getNeighbors(int partyId)
{
    vector<int> temp  = mEdges.at(partyId);
    vector<Party> neighbors;
    for(unsigned int i = 0; i < temp.size(); i++)
    {
        if(temp.at(i) !=0 )
        {
            neighbors.push_back(getPartyNotConst(i)); //new
        }
    }
    return neighbors;
}

vector<int> Graph::getNeighborsWeight(int partyId, vector<Party> neighbors)
{
    vector<int> weights;
    for(unsigned int i=0; i<neighbors.size(); i++)
    {
        weights.push_back(getEdgeWeight(partyId,neighbors.at(i).getId()));
    }
    return weights;
}

vector<Party> Graph::getParties()
{
    return mVertices;
}