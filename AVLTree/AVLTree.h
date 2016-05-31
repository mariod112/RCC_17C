/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AVLTree.h
 * Author: mario
 *
 * Created on May 30, 2016, 2:21 PM
 */
#include "AVLTreeNode.h"
#include <string>

using namespace std;

#ifndef AVLTREE_H
#define AVLTREE_H

class AVLTree {
private:
public:
        AVLTreeNode* root;
public:
    AVLTree();
    AVLTree(AVLTree& orig);
    int height(AVLTreeNode* node);
    void insert(int data);
    void balance(AVLTreeNode* node);
    AVLTreeNode* leftRotate(AVLTreeNode* node);
    AVLTreeNode* rightRotate(AVLTreeNode* node);
    AVLTreeNode* leftRightRotate(AVLTreeNode* node);
    AVLTreeNode* rightLeftRotate(AVLTreeNode* node);
    void remove(int data);
    int findMin(AVLTreeNode* node);
    int findMax(AVLTreeNode* node);
    string toStringInOrder();
    string toStringPreOrder();
    string toStringPostOrder();
    virtual ~AVLTree();
private:
    void remove(int data, AVLTreeNode* start);
};

#endif /* AVLTREE_H */

