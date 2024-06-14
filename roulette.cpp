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
    virtual int Bet() = 0;
    static RandomNumber* createBet();
};
// Zach - added if statements to differentiate whether the number was red or not
class Red : public RandomNumber {
private:
int  playerBetR;
public:
// Zach- added contollers to each class to get input for betting and for the players selected number
Red(int playerBetR):
         playerBetR(playerBetR) { }

    void printBet() override {
        if (number % 2 == 0) {
            cout << "The color of the number is not Red you lose." << endl;
        } else {
            cout << "The color of the number is Red." << endl;
        }
        cout << "The random number is " << number << "." << endl;

    }
    //Zach - added bet function in order to return the value for Halmar's class
    int Bet(){
        if (number % 2 == 0) {
            playerBetR = -playerBetR;
            return playerBetR;

        } else {

            return  playerBetR;
        }
    }
};
// Zach - added if statements to differentiate whether the number was black or not
class Black : public RandomNumber {
private:
    int playerBetB;
public:

    Black(int playerBetB):
        playerBetB(playerBetB) { }

    void printBet() override {
        if (number % 2 == 0) {
            cout << "The color of the number is Black." << endl;

        } else {
            cout << "The color of the number is not Black you lose." << endl;
        }
        cout << "The random number is " << number << "." << endl;

    }
    int Bet(){
        if (number % 2 == 0) {
            return playerBetB;

        } else {
            playerBetB = -playerBetB;
            return  playerBetB;
        }
    }
};
// Zach - added if statements to differentiate whether the number was green or not
class Green : public RandomNumber {
private:
    int playerBetG;
public:

    Green(int playerBetG):
        playerBetG(playerBetG) { }

    void printBet() override {
        if (number == 0) {
            cout << "The color of the number is Green." << endl;
        } else {
            cout << "The color of the number is not Green you lose." << endl;
        }
        cout << "The random number is " << number << "." << endl;

    }
    int Bet(){
        if (number == 0) {
            return playerBetG;

        } else {
            playerBetG = -playerBetG;
            return  playerBetG;
        }
    }
};
// Zach - removed the if statements for colors because they were not necessary if the player chose to bet on a number
class IndividualNumber : public RandomNumber {
private:
    int userNumber;
    int playerBetN;
public:

    IndividualNumber(int playerBetN, int userNumber):
        playerBetN(playerBetN), userNumber(userNumber) { }

    void printBet() override {

        cout << "The random number is " << number << "." << endl;

    }

    int Bet(){
        if (number == userNumber) {
            return playerBetN;

        } else {
            playerBetN = -playerBetN;
            return  playerBetN;
        }
    }
};

RandomNumber* RandomNumber::createBet() {
    char bet;
    cout << "Choose your bet (r for Red, b for Black, g for Green, n for Number): ";
    cin >> bet;

    int playerBet;
    cout << "Place your bet: " << endl;
    cin >> playerBet;

    if (bet == 'n') {
        int playerNumber;
        cout << "Pick a number from 0 to 37" << endl;
        cin >> playerNumber;
        IndividualNumber* betInstance = new IndividualNumber(playerBet, playerNumber);
        return betInstance;
    } else if (bet == 'g') {
        return new Green(playerBet);
    } else if (bet == 'b') {
        return new Black(playerBet);
    } else if (bet == 'r') {
        return new Red(playerBet);
    } else {
        cout << "Invalid bet type!" << endl;
        return nullptr;
    }
}

int main() {
    RandomNumber* bet = RandomNumber::createBet();
    bet->printBet();

    cout << bet->Bet() << endl;
    return 0;
}
