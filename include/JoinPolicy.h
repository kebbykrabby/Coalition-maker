#pragma once
#include <vector>
#include "Coalition.h"



using std:: vector;

// class Coalition;
class JoinPolicy {
    public:
        JoinPolicy() = default;
        JoinPolicy(const JoinPolicy& other) = default;
        JoinPolicy(JoinPolicy&& other) noexcept = default;
        virtual Coalition join(vector<Coalition> offersC ) = 0;
        virtual char getType() = 0;
        virtual ~JoinPolicy() = default;
        JoinPolicy &operator =(const JoinPolicy &other) = default;
        JoinPolicy& operator=(JoinPolicy&& other) noexcept = delete;

        
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        MandatesJoinPolicy()=default;
        MandatesJoinPolicy(const MandatesJoinPolicy& other) = default;
        MandatesJoinPolicy(MandatesJoinPolicy&& other) noexcept = default;
        virtual Coalition join(vector<Coalition> offersC);
        virtual char getType();
        ~MandatesJoinPolicy() = default ;
        MandatesJoinPolicy &operator =(const MandatesJoinPolicy &other) = default;
        MandatesJoinPolicy& operator=(MandatesJoinPolicy&& other) noexcept = delete;

        
};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
        LastOfferJoinPolicy()=default;
        LastOfferJoinPolicy(const LastOfferJoinPolicy& other) = default;
        LastOfferJoinPolicy(LastOfferJoinPolicy&& other) noexcept = default;
        virtual Coalition join(vector<Coalition> offersC);
        virtual char getType();
        ~LastOfferJoinPolicy() = default ;
        LastOfferJoinPolicy &operator =(const LastOfferJoinPolicy &other) = default;
        LastOfferJoinPolicy& operator=(LastOfferJoinPolicy&& other) noexcept = delete;

}; 