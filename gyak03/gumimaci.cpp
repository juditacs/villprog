/*
 * gumimaci.cpp
 * Copyright (C) 2016 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <cstdio>

class Person {
public:
    char firstname[20];
    char lastname[20];
    char taxid[10];
    char private_key[2000];
    int rank;

    Person* recommender;
};

class Company {
public:
    char name[50];
    char tax_number[11];
    char private_key[2000];

    Company* recommender;
};

Person* find_root(Person* p) {
    while(p->recommender != NULL)
        p = p->recommender;
    return p;
}

const Person& find_root_rec(const Person& p) {
    if (p.recommender == NULL)
        return p;
    return find_root_rec(*(p.recommender));
}

void print(const Person& p) {
    printf("%s %s %s %s\n", p.firstname, p.lastname, p.taxid, p.private_key);
}

void print(const Company& c) {
    printf("const: %s %s %s\n", c.name, c.tax_number, c.private_key);
}

void print(Company& c) {
    printf("nem const: %s %s %s\n", c.name, c.tax_number, c.private_key);
}

void rank_people_iter(Person& p) {
    int len;
    Person* iter = &p;
    for(len=1; iter->recommender!=NULL; len++) iter=iter->recommender;
    for(iter=&p; iter!=NULL; iter=iter->recommender) {
        iter->rank = len-1;
        len--;
    }
}

int rank_people_rec(Person& p, int r=0) {
    if (p.recommender != NULL)
        r = rank_people_rec(*(p.recommender), r);
    p.rank = r;
    return r+1;
}

int main(int argc, char* argv[]) {
    Person parray[1000];
    for (int i=0;i<1000-1;i++) parray[i].recommender = &(parray[i+1]);
    parray[1000-1].recommender = NULL;
    rank_people_rec(parray[0]);
    printf("0th rank: %d\n999th rank: %d\n", parray[0].rank, parray[999].rank);

    Person p = {"Gipsz", "Jakab", "123", "456", -1, NULL};

    print(p);
    printf("%s\n", p.firstname);

    Company c = {"Lehuto kft.", "123", "456-3-45", NULL};
    print(c);
}

