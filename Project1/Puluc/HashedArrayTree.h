/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HashedArrayTree.h
 * Author: mdiaz
 *
 * Created on June 2, 2016, 6:08 PM
 */

#include <string>
#include <vector>
#include "TreeBoardColumn.h"

using namespace std;

#ifndef HASHEDARRAYTREE_H
#define HASHEDARRAYTREE_H

class HashedArrayTree {
    private:
    int size;
    vector<TreeBoardColumn> hashedArray;    
public:
    HashedArrayTree(int size);
    HashedArrayTree(const HashedArrayTree& orig);
    void insert(string key, TreeBoardColumn column);
    TreeBoardColumn getColumn(string key);
    vector<TreeBoardColumn>::iterator getBegin();
    vector<TreeBoardColumn>::iterator getEnd();
    int getSize();
    virtual ~HashedArrayTree();
private:
    int hashFunction(string key);

};

#endif /* HASHEDARRAYTREE_H */

