#ifndef SCORE_H
#define SCORE_H

class Score {
private:
    int score;
    int gain;
    int loss;
    int rounds;
public:
    Score(int score = 1000, int gain = 0, int loss = 0, int rounds = 0);

    int getScore();
    void setScore(int base);

    int getGains();
    void setGains(int amount);

    int getLosses();
    void setLosses(int amount);

    int getRounds();
    void setRounds(int round);

    void winPoints(int points);
    void losePoints(int points);

    void display() const;
};

#endif // SCORE_H
