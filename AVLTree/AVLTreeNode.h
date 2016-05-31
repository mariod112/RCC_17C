/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AVLTreeNode.h
 * Author: mario
 *
 * Created on May 30, 2016, 2:22 PM
 */

#include <string>

using namespace std;

#ifndef AVLTREENODE_H
#define AVLTREENODE_H

class AVLTreeNode {
private:
    int data;
    AVLTreeNode* left;
    AVLTreeNode* right;
    AVLTreeNode* parent;
    int balance;
public:
    AVLTreeNode(int data, AVLTreeNode* parent);
    AVLTreeNode(AVLTreeNode& orig);
    int getData();
    int getBalance();
    AVLTreeNode* getLeft();
    AVLTreeNode* getRight();
    AVLTreeNode* getParent();
    void setData(int data);
    void setBalance(int balance);
    void setLeft(AVLTreeNode*);
    void setRight(AVLTreeNode*);
    void setParent(AVLTreeNode*);
    string toStringInOrder();
    string toStringPreOrder();
    string toStringPostOrder();
    virtual ~AVLTreeNode();
private:

};

#endif /* AVLTREENODE_H */

