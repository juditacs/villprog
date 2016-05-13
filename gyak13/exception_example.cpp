/*
 * exception_example.cpp
 * Copyright (C) 2016 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <exception>
#include <cstdlib>
#include <string>

class NegativeAgeException: public std::out_of_range {
public:
    NegativeAgeException(std::string s): std::out_of_range(s) {}
    NegativeAgeException(const NegativeAgeException&): std::out_of_range("alma")
    {std::cout<<"NegativeAgeException copy ctor"<<std::endl;}
};

void printAge(int a) {
    const NegativeAgeException n("Invalid age");
    //if (a < 0) throw NegativeAgeException(std::string("Invalid age: ") + std::to_string(a)); // to_string C++11-tol
    if (a < 0) throw NegativeAgeException(std::string("Invalid age"));
    std::cout << a << std::endl;
}

int main(int argc, char* argv[]) {
    int x;
    if (argc > 1) x = atoi(argv[1]);
    else {
        std::cerr << "Usage: " << argv[0] << " N" << std::endl;
        return -1;
    }
    try {
        printAge(x);
    }
    catch (NegativeAgeException& n) {
        std::cerr << "NegativeAgeException caught [" << n.what() << "]\n";
    }
    catch (std::out_of_range& e) {
        std::cerr << "std::out_of_range caught [" << e.what() << "]\n";
    }
    catch (std::exception& e) {
        std::cerr << "std::exception caught [" << e.what() << "]\n";
    }
    catch (...) {
        std::cerr << "Unknown exception caught\n";
    }
}

