#include "Score.h"
#include <iostream>

Score::Score(int score, int gain, int loss, int rounds):
    score(score), gain(gain), loss(loss), rounds(rounds) {}

//Getters and Setters
int Score::getScore() {
    return score;
}
void Score::setScore(int base) {
    score = base;
}

int Score::getGains() {
    return gain;
}
void Score::setGains(int amount) {
    gain = amount;
}

int Score::getLosses() {
    return loss;
}
void Score::setLosses(int amount) {
    loss = amount;
}

int Score::getRounds() {
    return rounds;
}
void Score::setRounds(int round) {
    rounds = round;
}

//Increase Score and Gain assuming it's after a round
void Score::winPoints(int points) {
    score += points;
    gain += points;
    rounds++;
}

//Decrease Score and Increase Loss assuming it's after a round
void Score::losePoints(int points) {
    score -= points;
    loss += points;
    rounds++;
}

// Method to display the current state of the score
void Score::display() const {
    std::cout << "Score: " << score << ", Gains: " << gain
              << ", Losses: " << loss << ", Rounds: " << rounds << std::endl;
}
