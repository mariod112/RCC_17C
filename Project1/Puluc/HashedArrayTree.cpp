/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HashedArrayTree.cpp
 * Author: mdiaz
 * 
 * Created on June 2, 2016, 6:08 PM
 */

#include "HashedArrayTree.h"
#include <vector>
#include <list>
#include <string>
#include <math.h>

using namespace std;

HashedArrayTree::HashedArrayTree(int size) : size(size), hashedArray(size) {
}

HashedArrayTree::HashedArrayTree(const HashedArrayTree& orig) {
    this->hashedArray = orig.hashedArray;
}

int HashedArrayTree::hashFunction(string key)
{
    int index = 0;
    
    index += (int)key.at(key.size() - 1) - 48;

    return index;
}

void HashedArrayTree::insert(string key, TreeBoardColumn column)
{
    hashedArray[hashFunction(key) % 10] = column;
}

TreeBoardColumn HashedArrayTree::getColumn(string key)
{
    return hashedArray[hashFunction(key) % 10];
}

vector<TreeBoardColumn>::iterator HashedArrayTree::getBegin()
{
    return hashedArray.begin();
}

vector<TreeBoardColumn>::iterator HashedArrayTree::getEnd()
{
    return hashedArray.end();
}

int HashedArrayTree::getSize()
{
    return size;
}
HashedArrayTree::~HashedArrayTree() {
}

