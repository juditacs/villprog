/*
 * Set.cpp
 * Copyright (C) 2016 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

template <typename T>
class Set {
    int elementNum;
    T* pData;
public:
    Set(): elementNum(0), pData(NULL) {}
    Set(const Set& rhs) {
        pData = NULL;
        elementNum = 0;
        *this = rhs;
    }
    Set& operator=(const Set& rhs) {
        if (this == &rhs) return *this;
        delete[] pData;
        elementNum = rhs.elementNum;
        if (elementNum > 0) {
            pData = new T[elementNum];
            for(int i=0; i<elementNum; i++) pData[i] = rhs.pData[i];
        }
        else { pData = NULL; }
        return *this;
    }
    ~Set() {
        delete[] pData;
    }
    void insert(const T& newElement) {
        if (!isElement(newElement)) {
            T* temp = new T[elementNum+1];
            for(int i=0;i<elementNum;i++) temp[i] = pData[i];
            temp[elementNum] = newElement;
            delete[] pData;
            pData = temp;
            elementNum++;
        }
    }
    bool isElement(const T& elem) const {
        for(int i=0; i<elementNum; i++) {
            if(pData[i] == elem) return true;
        }
        return false;
    }
    void remove(const T& elem) {
        if(isElement(elem)) {
            int i=0;
            for(; i<elementNum; i++) {
                if(pData[i] == elem) break;
            }
            for(; i<elementNum-1; i++) {
                pData[i] = pData[i+1];
            }
            elementNum--;
        }
    }
    void print() const {
        for(int i=0; i<elementNum; i++)
            std::cout << pData[i] << " ";
        std::cout << std::endl;
    }
};

int main(int argc, char* argv[]) {
    Set<int> s1, s2;
    s1.insert(2);
    s1.insert(2);
    s1.insert(3);
    s1.print();
    Set<int> s3 = s1;
    s2 = s1;
    s2.remove(4);
    s2.remove(2);
    s2.print();
    s1.print();
    s3 = s2 = s1;
    s2.print();
    s3.print();
    std::cout << std::boolalpha << s3.isElement(3) << std::endl;
}

