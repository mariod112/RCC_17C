/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HashArray.h
 * Author: mario
 *
 * Created on May 31, 2016, 5:47 PM
 */
#include <string>
#include <vector>
#include "BoardColumn.h"

using namespace std;

#ifndef HASHARRAY_H
#define HASHARRAY_H

class HashArray {
private:
    int size;
    vector<BoardColumn> hashedArray;
public:
    HashArray(int size);
    HashArray(const HashArray& orig);
    void insert(string key, BoardColumn column);
    BoardColumn getColumn(string key);
    vector<BoardColumn>::iterator getBegin();
    vector<BoardColumn>::iterator getEnd();
    int getSize();
    virtual ~HashArray();
private:
    int hashFunction(string key);

};

#endif /* HASHARRAY_H */

