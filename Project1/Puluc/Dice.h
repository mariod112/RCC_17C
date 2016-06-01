/* 
 * File:   Dice.h
 * Author: mario
 *
 * Created on May 1, 2016, 6:44 PM
 */

#include <list>
#include <string>

using namespace std;

#ifndef DICE_H
#define DICE_H

class Dice {
private:
    int numberOfDice;
    int maxValue;
    int minValue;
    list<int> dice;
public:
    Dice(int numberOfDice, int maxValue, int minValue);
    Dice(const Dice& orig);
    int Roll();
    string toString();
    virtual ~Dice();
};

#endif /* DICE_H */

