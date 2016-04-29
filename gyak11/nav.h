/*
 * nav.h
 * Copyright (C) 2016 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef NAV_H
#define NAV_H


class NAV_Product {
public:
    NAV_Product(int VAT, int Price){}
};
void NAV_AddItems(NAV_Product*) {}

class Line {
public:
    Line(unsigned char rgb[3], std::string text) {}
};
void PrintLine(Line) {}

#endif /* !NAV_H */
