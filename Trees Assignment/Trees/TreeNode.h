/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TreeNode.h
 * Author: mdiaz
 *
 * Created on May 20, 2016, 9:32 AM
 */

#include <list>

using namespace std;

#ifndef TREENODE_H
#define TREENODE_H

class TreeNode {
private:
    int data;
    int m;
    int level;
    TreeNode* parent;
    list<TreeNode*> children;
public:
    TreeNode(int m);
    TreeNode(TreeNode& orig);
    bool addChild(int data);
    bool insertData(int data, int level);
    int getData();
    void setData(int data);
    int getLevel();
    void setLevel(int level);
    TreeNode* getParent();
    void setParent(TreeNode* parent);
    list<TreeNode*>* getChildren();
    bool isLeaf();
    bool isFull();
    void printChildren();
    virtual ~TreeNode();
};

#endif /* TREENODE_H */

