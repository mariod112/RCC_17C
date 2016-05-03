/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dice.cpp
 * Author: mario
 * 
 * Created on May 1, 2016, 6:44 PM
 */

#include "Dice.h"
#include <numeric>
#include <string>
#include <algorithm>

using namespace std;

Dice::Dice(int numberOfDice, int maxValue, int minValue) {
    srand(static_cast<unsigned int>(time(0)));
    this->numberOfDice = numberOfDice;
    this->maxValue = maxValue;
    this->minValue = minValue;  
}

Dice::Dice(const Dice& orig) {
    this->numberOfDice = orig.numberOfDice;
    this->maxValue = orig.maxValue;
    this->minValue = orig.minValue; 
}

int Dice::Roll()
{
    int totalValue;
    
    dice.clear();//start a new roll
    
    for(int i = 0; i < numberOfDice; i++)
        dice.push_back(rand() % (maxValue - minValue + 1) + minValue);
    
    totalValue = accumulate(dice.begin(),dice.end(),0);
    
    if(totalValue == 0)
        totalValue = 5;
    
    return totalValue;
}

string Dice::toString()
{
    string diceString;
    //sort(dice.begin(), dice.end());
    
    for(int value: dice)
    {
        diceString += to_string(value) + ",";
    }
    
    return diceString;
}

Dice::~Dice() {
}

