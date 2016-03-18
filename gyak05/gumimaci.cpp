/*
 * gumimaci.cpp
 * Copyright (C) 2016 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <cstdio>
#include <cstring>

class Person {
    char* firstname;
    char* lastname;
    char taxid[10];
    char private_key[2000];
    int rank;

    Person* recommender;
public:
    Person(const char* firstname, const char* lastname) {
        this->firstname = new char[strlen(firstname)+1];
        strcpy(this->firstname, firstname);
        this->lastname = new char[strlen(lastname)+1];
        strcpy(this->lastname, lastname);
    }
    Person(const Person& rhs) { // right hand side
        this->firstname = new char[strlen(rhs.firstname)+1];
        strcpy(this->firstname, rhs.firstname);
        this->lastname = new char[strlen(rhs.lastname)+1];
        strcpy(this->lastname, rhs.lastname);
    }
    ~Person() {if (firstname) delete[] firstname;
        if (lastname) delete[] lastname;}
    Person& operator=(const Person& rhs) {
        setLastname(rhs.lastname);
        setFirstname(rhs.firstname);
        return *this;
    }
    const char* getFirstname() {return firstname;}
    void setLastname(const char* lastname) {
        delete[] this->lastname;
        this->lastname = new char[strlen(lastname)+1];
        strcpy(this->lastname, lastname);
    }
    void setFirstname(const char* firstname) {
        delete[] this->firstname;
        this->firstname = new char[strlen(firstname)+1];
        strcpy(this->firstname, firstname);
    }
    void printName() {
        printf("%s %s\n", firstname, lastname);
    }
};

int main(int argc, char* argv[]) {
    Person p("Pista", "Kis");
    Person p2(p), p3("A", "B");
    p.setLastname(argv[1]);
    p.printName();
    p2.printName();

    p3 = p;
    p.setLastname(argv[2]);
    p3.printName();
}

