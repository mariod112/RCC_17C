/* 
 * File:   main.cpp
 * Author: mario
 *
 * Created on May 1, 2016, 4:51 PM
 */

#include <cstdlib>
#include <iostream>
#include "PulucGame.h"
#include "Dice.h"
#include "BoardColumn.h"
#include "Board.h"

#include "HashArray.h"


#include "Token.h"
#include "TokenTree.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) { 
    Token token1(1,1,"M1");
    Token token2(2,2,"C2");
    
    TokenTree tree;
    tree.insert(token1);
    tree.insert(token2);
    cout << tree.toString() << endl;
    
//    PulucGame puluc;
//    string tempName;
//    int from;
//    string direction;
//    bool directionBool;
//    bool validFrom = false;
//    bool validDirection = false;
//    bool validMove = true;//make first move
//    
//    cout << "Rules available at: http://www.boardgamesoftheworld.com/puluc.html" <<endl;
    
//    cout << "Please Enter Player 1 name: ";
//    cin >> tempName;
//    puluc.setPlayer1Name(tempName);
//    
//    cout << "Please Enter Player 2 name: ";
//    cin >> tempName;
//    puluc.setPlayer2Name(tempName);
//    
//    
//    puluc.setUpBoard();
//    
//    do
//    {
//        if(validMove)//only go to next turn after valid move
//        {
//            cout << puluc.boardString();
//            cout << puluc.nextTurn() << endl;
//        }
//        
//        while(!validFrom)
//        {
//            cout << "Which row would you like to move from: 0 for base, -1 to pass, or -2 to exit)? ";
//            cin >> from;
//
//            if(from == -2)
//            {
//                cout << "Exit";
//                return 0;
//            }
//            else if(from == 0 || from == -1)//move from base skip direction
//            {
//                validFrom = true;
//                validDirection = true;
//            }                
//            else if((from < 0) && (from > 11))
//            {
//                cout << "----Invalid input please try again----" << endl;
//                validFrom = false;
//            }
//            else
//                validFrom = true;
//        }
//
//        while(!validDirection)
//        {
//            cout << "Move up (u) or down (d) or -1 to exit?";
//            cin >> direction;
//
//            switch(direction.at(0))
//            {
//                case 'u':
//                    directionBool = true;
//                    validDirection = true;
//                    break;
//                case 'd':
//                    directionBool = false;
//                    validDirection = true;
//                    break;
//                case '-':
//                    cout << "Exit";
//                    return 0;
//                default:
//                    cout << "----Invalid input please try again----";
//                    validDirection = false;
//                    break;
//            }
//        }
//
//        validMove = puluc.nextMove(from,directionBool);
//        
//        if(!validMove)
//            cout << "----Invalid move please try again----" << endl;
// 
//        validFrom =false;
//        validDirection = false;
//        
//    }while(!puluc.getGameEnded());
//    
//    cout << puluc.boardString();
//    cout << puluc.winnerString();
//   
    return 0;
}

