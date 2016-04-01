/*
 * bunny.cpp
 * Copyright (C) 2016 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <string>

class Egg {
    std::string color;
    int size;
public:
    Egg(std::string color="red", int size=5): color(color), size(size) {}
    bool operator==(const Egg& rhs) {
        return (color == rhs.color) & (size == rhs.size);
    }
    bool operator!=(const Egg& rhs) {
        return !(*this == rhs);
    }

};

class Bunny {
    Egg* pData;
    int elementNum;
public:
    Bunny(): pData(NULL), elementNum(0) {}
    void addEgg(const Egg& egg) {
        if (elementNum==0) {
            pData = new Egg[1];
        }
        else {
            Egg* newData = new Egg[elementNum+1];
            for (int i=0; i<elementNum; i++) newData[i] = pData[i];
            delete[] pData;
            pData = newData;
        }
        pData[elementNum] = egg;
        elementNum++;
    }
    ~Bunny() { delete[] pData; }
    Bunny& operator=(const Bunny& rhs) {
        //std::cout << "op=" << std::endl;
        if (this == &rhs) return *this;
        if (pData) delete[] pData;
        elementNum = rhs.elementNum;
        if (elementNum==0) pData = NULL;
        else {
            pData = new Egg[elementNum];
            for(int i=0; i < elementNum; i++)
                pData[i] = rhs.pData[i];
        }
        return *this;
    }
    Bunny (const Bunny& other) {
        //std::cout << "copy ctor" << std::endl;
        pData = NULL;
        *this = other;
    }
    bool operator==(const Bunny& rhs) {
        if (elementNum != rhs.elementNum) return false;
        for (int i=0; i<elementNum; i++)
            if (pData[i] != rhs.pData[i]) return false;
        return true;
    }
};

// HF kiiro es beolvaso operatorok tulterhelese mindket osztalyra
// fajlbol olvasas
int main(int argc, char* argv[]) {
    Egg e1("blue", 16), e2;
    Bunny b1;
    b1.addEgg(e1);
    b1.addEgg(e2);
    Bunny b2;
    std::cout << std::boolalpha << (b1 == b2) << std::endl;
    b2 = b1;
    std::cout << (b1 == b2) << std::endl;
}

