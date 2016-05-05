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
#include "Board.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Dice dice(4, 1, 0);
    BoardColumn column1;
    BoardColumn column2;
    BoardColumn column3;
    Board board;
    
    int diceRoll = dice.Roll();
    
    string column1Name = "1";
    string column1Name1 = "2";
    string column3Name = "3";
    
    board.addColumn(column1Name,&column1);
    board.addColumn(column1Name1,&column2);
    board.addColumn(column3Name,&column3);
    
    Token token1(1,1,"M1");
    Token token2(1,2,"M2");
    Token token3(2,3,"C1");
    Token token4(2,2,"C2");

    
    column1.addToken(token1);
    column1.addToken(token2);
    column2.addToken(token2);
    column2.addToken(token4);
    
    cout << "DiceRoll: "<< dice.toString() << ": " << diceRoll << endl;
    cout <<  board.toString() << endl;
 
    cout << "Move from 1 to 2" << endl;
    
    if(column2.peekTop() != column1.peekTop())
        board.moveColumn("4","2");
    
    board.moveTokenFromHome("1",1);
    board.moveTokenIntoHome(token4);
    board.killToken(token3);
    
    cout <<  board.toString() << endl;
    
    return 0;
}

