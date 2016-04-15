/*
 * gumimaci.cpp
 * Copyright (C) 2016 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <string>

class Partner {
protected:
    Partner* recommender;
    std::string name;
public:
    Partner(std::string name): name(name) {}
    void setRecommender(Partner* p) {recommender = p;}
    void printRecommender() const {recommender->print(); std::cout << std::endl;}
    //virtual void print() const {std::cout << "Partner: " << name;}
    virtual void print() const = 0;
    virtual ~Partner() {std::cout << "Partner " << name << " destroyed" << std::endl;}
};
class Company: public Partner {
    char taxnum[12];
public:
    Company(std::string name): Partner(name) {}
    void setTaxnum(char t[12]) {for(int i=0; i<12; i++) taxnum[i] = t[i];}
    void print() const {std::cout << "Company: " << name;}
    ~Company() {std::cout << "Company " << name << " destroyed" << std::endl;}
};
class Person: public Partner {
    char taxid[11];
public:
    Person(std::string name): Partner(name) {}
    void setTaxid(char t[11]) {for(int i=0; i<11; i++) taxid[i] = t[i];}
    void print() const {std::cout << "Person: " << name;}
    ~Person() {std::cout << "Person " << name << " destroyed" << std::endl;}
};

int main(int argc, char* argv[]) {
    Partner** p = new Partner*[2];
    p[0] = new Person("Kati");
    p[1] = new Company("Microsoft");
    p[0]->print();
    std::cout << std::endl;
    p[1]->print();
    std::cout << std::endl;
    delete[] p;
}
