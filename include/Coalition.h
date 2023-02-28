#pragma once
#include <vector>
using std::vector;

class Coalition{
    public:
        Coalition();
        Coalition(int id);
        int getMandates() const;
        void addMandates(int mandates) ;
        int getId() const;
        void addParty(int partyId);
        void setId(int id);
        vector<int> getAgents() const;
        void addAgent(int id);
        vector<int> getParties() const;
    private:
        int mId;
        int mMandates;
        vector<int> mParties;
        vector<int> mAgents;


};