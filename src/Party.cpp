#include "Party.h"
#include "Simulation.h"
#include "Agent.h"

#include <iostream>
using std:: cout;
using std::endl;

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), mOffers(), timer(0)
{
    // You can change the implementation of the constructor, but not the signature!
}

Party::Party(const Party &other) : mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(), mState(other.mState), mOffers(other.mOffers), timer(other.timer)
{
    char type = other.mJoinPolicy->getType();
    if (type == 'M')
    {
        mJoinPolicy = new MandatesJoinPolicy();
    }
    else
    {
        mJoinPolicy = new LastOfferJoinPolicy();
    }
}
Party::Party(Party &&other) noexcept : mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy), mState(other.mState), mOffers(other.mOffers), timer(other.timer)
{
    other.mJoinPolicy = nullptr;
}

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string &Party::getName() const
{
    return mName;
}

vector<Coalition> Party::getOffers()
{
    return mOffers;
}
void Party::addOffer(Coalition newOffer)
{
    mOffers.push_back(newOffer);
    if (this->getState() == Waiting)
    {
        this->setState(CollectingOffers);
    }
}

void Party::step(Simulation &s)
{

    // TODO: implement this method
    if (timer > 2)
    {
        Coalition chosenOne = mJoinPolicy->join(mOffers);
        chosenOne.addParty(mId);
        chosenOne.addMandates(mMandates);
        
        this->setState(Joined);
        int coalitionId = chosenOne.getId();
        vector<Agent> agents = s.getAgents();
        for (unsigned int i = 0; i < agents.size(); i++)
        {
            if (agents.at(i).getCoalitionId() == coalitionId)
            {
                const Agent &other = agents.at(i);
                Agent newAgent = Agent(other);
                newAgent.setPartyId(mId);
                newAgent.setAgentId(agents.size());
                s.addAgent(newAgent);
                return;
            }
        }
    }
    else
    {
        if (this->getState() == 1)
        {
            cout << "collecting!" << endl;
            timer += 1;
        }
    }
    
}

int Party::getId() const
{
    return mId;
}

Party::~Party()
{
    delete mJoinPolicy;
    mJoinPolicy = nullptr;
}

Party &Party::operator=(const Party &other)
{
    if (this != &other)
    { 
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        mState = other.mState;
        mOffers = other.mOffers;
        timer = other.timer;
        char type = other.mJoinPolicy->getType();
        if (type == 'M')
        {
            mJoinPolicy = new MandatesJoinPolicy();
        }
        else
        {
            mJoinPolicy = new LastOfferJoinPolicy();
        }
    
    }
    return *this;
}

Party &Party::operator=(Party &&other) noexcept
{
    mId = other.mId;
    mName = other.mName;
    mMandates = other.mMandates;
    mJoinPolicy = other.mJoinPolicy;
    mState = other.mState;
    mOffers = other.mOffers;
    timer = other.timer;

    other.mJoinPolicy = nullptr;   

    return *this;
}