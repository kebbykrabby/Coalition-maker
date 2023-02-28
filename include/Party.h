#pragma once
#include <string>
#include <vector>
#include "JoinPolicy.h"
#include "Coalition.h"

using std::vector;
using std::string;

class Agent;
class JoinPolicy;
class Simulation;
// class Coalition;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 
    Party(const Party& other);
    Party(Party&& other) noexcept;
    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    vector<Coalition> getOffers();
    void addOffer(Coalition newOffer);
    ~Party();
    Party &operator = (const Party &other);
    Party& operator=(Party&& other) noexcept;

    int getId() const;
private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    vector<Coalition> mOffers;
    int timer;
};
