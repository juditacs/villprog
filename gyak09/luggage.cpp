/*
 * luggage.cpp
 * Copyright (C) 2016 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

class BaseLuggage {
protected:
    static const double baseProb;
public:
    virtual void PrintDetails() const = 0;
    virtual ~BaseLuggage() {}
};
class HandLuggage: public BaseLuggage {
    static const double handFact;
public:
    void PrintDetails() const {std::cout << "HandLuggage, " << baseProb * handFact << std::endl;}
};
class CheckedinLuggage: public BaseLuggage {
protected:
    static const double checkedInFact;
public:
    void PrintDetails() const {std::cout << "CheckedInLuggage, " << baseProb * checkedInFact << std::endl;}
};
class OversizeLuggage: public CheckedinLuggage {
public:
    void PrintDetails() const {std::cout << "OversizeLuggage, " << baseProb * checkedInFact << std::endl;}
};

const double BaseLuggage::baseProb = 0.5;
const double HandLuggage::handFact = 1.5;
const double CheckedinLuggage::checkedInFact = 1.2;

int main(int argc, char* argv[]) {
    BaseLuggage* luggages[3];
    luggages[0] = new HandLuggage;
    luggages[1] = new CheckedinLuggage;
    luggages[2] = new OversizeLuggage;
    for(int i=0; i<3; i++) luggages[i]->PrintDetails();
    for(int i=0; i<3; i++) delete luggages[i];
}

