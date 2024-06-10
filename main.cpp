#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class RandomNumber {
protected:
    int number;
public:
    RandomNumber() {
        srand(time(0));
        number = rand() % 37;
    }
    int getNumber() {
        return number;
    }
    virtual void printBet() = 0;
    static RandomNumber* createBet();
};

class Red : public RandomNumber {
public:
    void printBet() override {
        cout << "The random number is " << number << "." << endl;
        cout << "The color of the number is Red." << endl;
    }
};

class Black : public RandomNumber {
public:
    void printBet() override {
        cout << "The random number is " << number << "." << endl;
        cout << "The color of the number is Black." << endl;
    }
};

class Green : public RandomNumber {
public:
    void printBet() override {
        cout << "The random number is " << number << "." << endl;
        cout << "The color of the number is Green." << endl;
    }
};

class IndividualNumber : public RandomNumber {
private:
    int userNumber;
public:
    void printBet() override {
        cout << "The random number is " << number << "." << endl;
        if (number == 0) {
            cout << "The color of the number is Green." << endl;
        } else if (number % 2 == 0) {
            cout << "The color of the number is Black." << endl;
        } else {
            cout << "The color of the number is Red." << endl;
        }
    }
};

RandomNumber* RandomNumber::createBet() {
    char bet;
    cout << "Choose your bet (r for Red, b for Black, g for Green, n for Number): ";
    cin >> bet;

    if (bet == 'n') {
        IndividualNumber* betInstance = new IndividualNumber();
        return betInstance;
    } else if (bet == 'g') {
        return new Green();
    } else if (bet == 'b') {
        return new Black();
    } else if (bet == 'r') {
        return new Red();
    } else {
        cout << "Invalid bet type!" << endl;
        return nullptr;
    }
}

int main() {
    RandomNumber* bet = RandomNumber::createBet();
    bet->printBet();
    return 0;
}
