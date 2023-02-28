#pragma once
#include "Simulation.h"

#include "Graph.h"
#include "Party.h"
class SelectionPolicy { 
    public:
    SelectionPolicy() = default;
    SelectionPolicy(const SelectionPolicy& other) = default;
    SelectionPolicy(SelectionPolicy&& other) noexcept = default;
    virtual Party select(int partyId, Simulation *sim, int coalitionId) = 0;
    virtual ~SelectionPolicy() = default;
    SelectionPolicy &operator =(const SelectionPolicy &other) = default;
    SelectionPolicy& operator=(SelectionPolicy&& other) noexcept = delete;
    virtual char getType() = 0;
};

class MandatesSelectionPolicy: public SelectionPolicy{
    public:
    MandatesSelectionPolicy() = default;
    MandatesSelectionPolicy(const MandatesSelectionPolicy& other) = default;
    MandatesSelectionPolicy(MandatesSelectionPolicy&& other) noexcept = default;
    virtual Party select(int partyId, Simulation *sim, int coalitionId);
    virtual ~MandatesSelectionPolicy() = default  ;
    MandatesSelectionPolicy &operator =(const MandatesSelectionPolicy &other) = default;
    MandatesSelectionPolicy& operator=(MandatesSelectionPolicy&& other) noexcept = delete;
    virtual char getType() ;
 };

class EdgeWeightSelectionPolicy: public SelectionPolicy{ 
    public:
    EdgeWeightSelectionPolicy() = default;
    EdgeWeightSelectionPolicy(const EdgeWeightSelectionPolicy& other) = default;
    EdgeWeightSelectionPolicy(EdgeWeightSelectionPolicy&& other) noexcept = default;
    virtual Party select(int partyId, Simulation *sim, int coalitionId);
    virtual ~EdgeWeightSelectionPolicy() = default;
    EdgeWeightSelectionPolicy &operator =(const EdgeWeightSelectionPolicy &other) = default;
    EdgeWeightSelectionPolicy& operator=(EdgeWeightSelectionPolicy&& other) noexcept = delete;
    virtual char getType() ;
};