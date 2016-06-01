/* 
 * File:   BoardColumn.h
 * Author: mario
 *
 * Created on May 2, 2016, 5:07 PM
 */
#include <list>
#include <string>
#include "Token.h"

using namespace std;

#ifndef BOARDCOLUMN_H
#define BOARDCOLUMN_H

class BoardColumn {
private:
    list<Token> column;
public:
    BoardColumn();
    BoardColumn(const BoardColumn& orig);
    Token peekTop();
    int getTopPlayer();
    list<Token> getColumnTokens();
    list<Token> removeColumnTokens();
    void addTokenListOnTop(list<Token> tokenList);
    void addToken(Token token);
    void clearColumn();
    void moveOnTopColumn(BoardColumn boardColumn);
    Token pullTopToken();
    string toString();
    virtual ~BoardColumn();

};

#endif /* BOARDCOLUMN_H */

