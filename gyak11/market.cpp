/*
 * market.cpp
 * Copyright (C) 2016 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <sstream>
#include <string>

#include "nav.h"

class IPrintable {
public:
    virtual std::string toString() const = 0;
};
class IBookable {
public:
    virtual int getPrice() const = 0;
};

class Product : public IPrintable, public IBookable{
private:
    std::string name;
    int price;
    static const int VAT;
public:
    Product(std::string pname, int pprice) : name(pname), price(pprice) {}
    Product(int pprice): name("meglepetes"), price(pprice) {}
    std::string toString() const {
        std::stringstream ss;
        ss << name << ": " << price;
        return ss.str();
    }
    int getPrice() const { return price; }
    operator int() const { return getPrice(); }
    operator Line() const { unsigned char t[3] = {0, 0, 0};
        return Line(t, toString()); }
    // kinek kell felszabaditania a pointert?
    // A dokumentaciobol ki kell derulnie
    operator NAV_Product* () const { return new NAV_Product(27, getPrice()); }
};
const int Product::VAT = 27;

// 10. gyakorlat osztalyai
class ShopDetails: public IPrintable {
    std::string name;
public:
    std::string toString() { return name; }
    // szorgalmi konverzios operator Line-ra
};

class Printer {
public:
    void AddElementsToPrint(IPrintable* printables[], int count) {
        for(int i=0; i<count; i++) std::cout << printables[i]->toString() << std::endl;
    }

};
int operator+(const Product& lhs, const Product& rhs) {
    return lhs.getPrice() + rhs.getPrice();
}
int main(int argc, char* argv[]) {
    Product duck("kacsa", 4500);
    Product chicken("csirke", 2200);
    int delivery = 900;
    int total = Product(delivery) + duck;
    std::cout << "Fizetendo: " << total << std::endl;
    NAV_AddItems(duck);
    NAV_AddItems(chicken);
}

