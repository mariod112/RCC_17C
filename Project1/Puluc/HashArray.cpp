/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HashArray.cpp
 * Author: mario
 * 
 * Created on May 31, 2016, 5:47 PM
 */

#include "HashArray.h"
#include <vector>
#include <list>
#include <string>
#include <math.h>

using namespace std;

HashArray::HashArray(int size): size(size), hashedArray(size) {
}

HashArray::HashArray(const HashArray& orig) {
    this->hashedArray = orig.hashedArray;
}

int HashArray::hashFunction(string key)
{
    int index = 0;

    index += (int)key.at(key.size() - 1) - 48;

    return index;
}

void HashArray::insert(string key, BoardColumn column)
{
    hashedArray[hashFunction(key) % 10] = column;
}

BoardColumn HashArray::getColumn(string key)
{
    return hashedArray[hashFunction(key) % 10];
}

vector<BoardColumn>::iterator HashArray::getBegin()
{
    return hashedArray.begin();
}

vector<BoardColumn>::iterator HashArray::getEnd()
{
    return hashedArray.end();
}

int HashArray::getSize()
{
    return size;
}

HashArray::~HashArray() {
}

