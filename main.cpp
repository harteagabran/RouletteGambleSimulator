#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Score.h"
using namespace std;

//-Halmar - Modified this class from Zach's original to incorporate max score
    // don't want users to be able to bet more than they have
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
    static RandomNumber* createBet(int max);
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
    int Bet() override {
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
    int Bet() override{
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
    int Bet() override {
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

    int Bet() override {
        if (number == userNumber) {
            return playerBetN;

        } else {
            playerBetN = -playerBetN;
            return  playerBetN;
        }
    }
};
//-Halmar- modified here to implement a max bet commented out Zach's code to show what he did
RandomNumber* RandomNumber::createBet(int max) {
    char bet;
    cout << "Choose your bet (r for Red, b for Black, g for Green, n for Number): ";
    cin >> bet;

    //-Halmar- Added sentinal value in order to quit
    if(bet == 'z') {
        return 0;
    }

    int playerBet;
    /* Zach
    cout << "Place your bet: " << endl;
    cin >> playerBet;
    */
    while(true) {
        cout << "Place your bet: (max " << max << "): ";
        cin >> playerBet;
        //check if player bet is less than max and also greater than 0
        if(playerBet <= max && playerBet > 0) {
            break;
        } else {
            cout << "Bets must be between 0 and the max amount. Please try again." << endl;
        }
    }

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
    //-Halmar changed to use loop to keep going until score is less or equal to 0 or person quits
    Score score = Score();
    int points;
    int currentScore = score.getScore();
    char continueBet = 'y';

    while(currentScore > 0 && continueBet == 'y') {
        cout << "Round " << score.getRounds() + 1 << endl;
        //display Score
        score.display();
        cout << endl;

        //prompt for bet
        RandomNumber* bet = RandomNumber::createBet(score.getScore());;
        if(!bet) {
            cout << "Not a valid bet. Try Again!" << endl;
            continue;
        }
        bet->printBet();
        points = bet->Bet();

        //Zach class returns a value for bet so use it to calculate score
        if(points > 0) {
            score.winPoints(points);
        } else {
            score.losePoints(points);
        }

        //update score
        currentScore = score.getScore();

        //If no more left to play display
        if(currentScore <= 0) {
            break;
        } else {
            //ask if wanting to continue playing
            cout << "Play next round? ('y' to continue) ";
            cin >> continueBet;
        }
        cout << endl;
    }

    cout << endl;
    cout << "GAME OVER" << endl;
    cout << "Final Score: " << score.getScore() << endl;
    cout << "Gains: " << score.getGains() << endl;
    cout << "Loss: " << score.getLosses() << endl;
    cout << "Total Rounds: " << score.getRounds() << endl;
    return 0;
}
