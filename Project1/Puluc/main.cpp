/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: mario
 *
 * Created on May 1, 2016, 4:51 PM
 */

#include <cstdlib>
#include <iostream>
#include "Dice.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Dice dice(4, 1, 0);
    int diceRoll = dice.Roll();
    
    cout << "DiceRoll: "<< dice.toString() << ": " << diceRoll << endl;
    
    
    return 0;
}

