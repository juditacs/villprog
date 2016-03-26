#include <iostream>
#include <cstdlib>
#include <cstring>

class Account {
    const long id;
    double balance;
    static const double HUF_USD;
public:
    Account(long id, double balance=0): id(id), balance(balance) {}
    double convertToUSD() const { return balance * HUF_USD; }
    void setBalance(double b) {balance = b;}
};

const double Account::HUF_USD = 0.00355848;

int main(int argc, char* argv[]) {
    const Account* frozen[3];
    frozen[0] = new Account(3, 45);
    frozen[1] = new Account(3, 45);
    frozen[2] = new Account(3, 45);
    
    std::cout << frozen[0]->convertToUSD() << std::endl;
    //frozen[0]->setBalance(345); // nem erjuk el
    //Account a(1, atoi(argv[1]));
    //const Account ca(2, 1000);
    //const Account* pa = new Account(3, 2000);
    //std::cout << ca.convertToUSD() << std::endl;
    //std::cout << pa->convertToUSD() << std::endl;
    //delete pa;
}

