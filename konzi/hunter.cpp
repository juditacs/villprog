/*
 * hunter.cpp
 * Copyright (C) 2016 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

namespace Hunter {
    class Animal {
    protected:
        static const double basePrice;
    public:
        virtual void print() const = 0;
        virtual double getPrice() const = 0;
        virtual ~Animal() {}
    };
    class PolarBear: public Animal {
        static const double polarBearFactor;
    public:
        void print() const {
            std::cout << "PolarBear price: " << getPrice();
        }
        double getPrice() const {
            return basePrice * polarBearFactor;
        }
    };
    class Squirrel: public Animal {
        static const double squirrelFactor;
    public:
        void print() const {
            std::cout << "Squirrel price: " << getPrice();
        }
        double getPrice() const {
            return basePrice * squirrelFactor;
        }
    };
    class Rabbit: public Animal {
        static const double rabbitFactor;
    public:
        void print() const {
            std::cout << "Rabbit price: " << getPrice();
        }
        double getPrice() const {
            return basePrice * rabbitFactor;
        }
    };
    const double Animal::basePrice = 100000;
    const double PolarBear::polarBearFactor = 2.4;
    const double Rabbit::rabbitFactor = 0.3;
    const double Squirrel::squirrelFactor = 1.2;
}

int main(int argc, char* argv[]) {
    Hunter::PolarBear pb;
    Hunter::Animal* animals[3];
    animals[0] = new Hunter::PolarBear;
    animals[1] = new Hunter::Squirrel;
    animals[2] = new Hunter::Rabbit;

    for(int i=0; i<3; i++) {
        animals[i]->print();
        std::cout << std::endl;
    }

    for(int i=0; i<3; i++) delete animals[i];
}

