#include<iostream>
using namespace std;

// Abstract base class
class CentralBank {
protected:
    double ird; // interest rate for deposit
    double irl; // interest rate for loan

public:
    CentralBank() : ird(0.0), irl(0.0) {}

    virtual void getData() = 0;
    virtual void displayData() = 0;
    virtual void calculateInterestAmount(double principal, int years) = 0;
};

// Derived class NMB
class NMB : public CentralBank {
public:
    void getData() override {
        ird = 5.5;
        irl = 9.5;
    }

    void displayData() override {
        cout << "NMB Bank\nDeposit Rate: " << ird << "%\nLoan Rate: " << irl << "%\n";
    }

    void calculateInterestAmount(double principal, int years) override {
        double depositInterest = (principal * ird * years) / 100;
        double loanInterest = (principal * irl * years) / 100;
        cout << "Deposit Interest: " << depositInterest << endl;
        cout << "Loan Interest: " << loanInterest << endl;
    }
};

// Derived class GlobalBank
class GlobalBank : public CentralBank {
public:
    void getData() override {
        ird = 6.0;
        irl = 10.0;
    }

    void displayData() override {
        cout << "Global Bank\nDeposit Rate: " << ird << "%\nLoan Rate: " << irl << "%\n";
    }

    void calculateInterestAmount(double principal, int years) override {
        double depositInterest = (principal * ird * years) / 100;
        double loanInterest = (principal * irl * years) / 100;
        cout << "Deposit Interest: " << depositInterest << endl;
        cout << "Loan Interest: " << loanInterest << endl;
    }
};

int main() {
    CentralBank* bank;

    bank = new NMB();
    bank->getData();
    bank->displayData();
    bank->calculateInterestAmount(10000, 2);

    cout << "\n";

    bank = new GlobalBank();
    bank->getData();
    bank->displayData();
    bank->calculateInterestAmount(10000, 2);

    delete bank;

    return 0;
}
