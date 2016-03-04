/*
 * recursive_tests.cpp
 * Copyright (C) 2016 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>

#define doprint 0

class Big {
    char s[10000];
};

void left_recursive(Big b, int times) {
    if (times > 0) left_recursive(b, times-1);
    if (doprint==1)
        printf("%d\n", times);
}

void right_recursive(Big b, int start, int times) {
    if (doprint==1)
        printf("%d\n", start);
    if (times >= start) right_recursive(b, start+1, times);
}

void left_recursive_with_reference(const Big& b, int times) {
    if (times > 0) left_recursive_with_reference(b, times-1);
    if (doprint==1)
        printf("%d\n", times);
}

void right_recursive_with_reference(const Big& b, int start, int times) {
    if (doprint==1)
        printf("%d\n", start);
    if (times >= start) right_recursive_with_reference(b, start+1, times);
}

void iter(Big b, int times) {
    for(int i=0; i<times; i++)
        if (doprint==1)
            printf("%d\n", times);
}

int main(int argc, char* argv[]) {
   int times = atoi(argv[1]); 
   char typ = tolower(argv[2][0]);
   Big b;
   switch(typ) {
       case 'l': left_recursive(b, times); break;
       case 'r': right_recursive(b, 0, times); break;
       case 'a': left_recursive_with_reference(b, times); break;
       case 'b': right_recursive_with_reference(b, 0, times); break;
       case 'i': iter(b, times);
   }
}

