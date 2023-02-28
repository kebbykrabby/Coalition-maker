#include "Coalition.h"


Coalition :: Coalition() : mId(-1), mMandates(0), mParties(), mAgents()
{

}
Coalition :: Coalition(int id) : mId(id), mMandates(0), mParties(), mAgents()
{
}


int Coalition:: getMandates() const
{
    return mMandates;
}
void Coalition:: addMandates(int mandates)
{
    mMandates += mandates;
}
int Coalition::getId() const
{
    return mId;
}

void Coalition:: setId(int id)
{
    mId = id;
}
vector<int> Coalition:: getAgents() const
{
    return mAgents;
}
void Coalition:: addAgent(int id)
{
    mAgents.push_back(id);
}

void Coalition::addParty(int partyId)
{
   mParties.push_back(partyId);
}

vector<int> Coalition:: getParties() const
{
    return mParties;
}
