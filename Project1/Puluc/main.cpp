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
#include "BoardColumn.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Dice dice(4, 1, 0);
    BoardColumn column1;
    BoardColumn column2;
    
    int diceRoll = dice.Roll();
    
    Token token1(1,1,"M1");
    Token token2(1,2,"M2");
    Token token3(2,3,"C1");
    Token token4(2,2,"C2");

    
    column1.addToken(token1);
    column1.addToken(token4);
    column2.addToken(token2);
    column2.addToken(token3);
    
    cout << "DiceRoll: "<< dice.toString() << ": " << diceRoll << endl;
    cout << "1: " << column1.toString() << endl;
    cout << "2: " << column2.toString() << endl;
    
    cout << "Move from 1 to 2" << endl;
    
    if(column2.peekTop() != column1.peekTop())
        column2.moveColumn(&column1);
    
    cout << "1: " << column1.toString() << endl;
    cout << "2: " << column2.toString() << endl;
    
    return 0;
}

