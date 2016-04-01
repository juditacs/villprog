/*
 * date.cpp
 * Copyright (C) 2016 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

class Date {
    int year, month, day;
public:
    Date(int year=1970, int month=1, int day=1): year(year), month(month), day(day) {}
    friend std::ostream& operator<<(std::ostream& os, const Date& d);
    friend std::istream& operator>>(std::istream& is, Date& d);
};

std::ostream& operator<<(std::ostream& os, const Date& d) {
    os << '(' << d.year << ',' << d.month << ',' << d.day << ')';
    return os;
}

// szorgalmi: failbit allitsa
// hibakezeles a konstruktorban kellene
std::istream& operator>>(std::istream& is, Date& d) {
    is.ignore(1);
    is >> d.year;
    is.ignore(1);
    is >> d.month;
    is.ignore(1);
    is >> d.day;
    is.ignore(1);
    return is;
}

int main(int argc, char* argv[]) {
    Date d1(1995, 5, 13);
    std::cout << d1 << std::endl;
    Date d2;
    std::cin >> d2;
    std::cout << d2 << std::endl;
}

