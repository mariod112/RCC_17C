/* 
 * File:   Board.h
 * Author: mario
 *
 * Created on May 4, 2016, 5:09 PM
 */

#include "BoardColumn.h"
#include "TreeBoardColumn.h"
#include "HashedArrayTree.h"
#include <map>
#include <queue>
#include <set>
#include <list>
#include <string>


using namespace std;

#ifndef BOARD_H
#define BOARD_H

class Board {
private:
    //map<int,BoardColumn> board;
    HashedArrayTree board;
    queue<Token> player1Home;
    queue<Token> player2Home;
    set<Token> player1DeadTokens;
    set<Token> player2DeadTokens;
public:
    Board();
    Board(const Board& orig);
    void addColumn(int number, TreeBoardColumn column);
    void moveTokensInColumn(int from, int to);
    bool moveTokenFromHome(int to, int playerNumber);
    void moveTokenIntoHome(Token token);
    list<Token> getColumnTokens(int from);
    int getColumnPlayer(int from);
    void clearColumn(int column);
    void killToken(Token token);
    int getKillCount(int player);
    int getHomeCount(int player);
    bool checkPlayerFreeOnBoard(int player);
    string toString();
    virtual ~Board();

};

#endif /* BOARD_H */

