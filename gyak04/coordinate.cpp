/*
 * coordinate.cpp
 * Copyright (C) 2016 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <cstdio>

class Cooordinate {
public:
    double x, y;
    Cooordinate(double x, double y): x(x), y(y) {}
    // az explicit kulcsszoval tilthato az automatikus konverzio
    //explicit Cooordinate(int x): x(x), y(0) {
    Cooordinate(int x): x(x), y(0) {
        printf("konverzios konstruktor hivodott\n");
    }
    void print() {
        printf("%lf %lf\n", x, y);
    }
    Cooordinate& operator=(const Cooordinate& c) {
        this->x = c.x;
        this->y = c.y;
        printf("op= hivodott\n");
        return *this;
    }
};

int main(int argc, char* argv[]) {
    Cooordinate c(2, 3);
    c.print();
    int i = 2;
    Cooordinate c2(i);
    c2.print();
    c2 = 456;
    c2 = 'a';
    c2.print();
    Cooordinate c3(c2); // masolo konstruktort a fordito generalja
}
