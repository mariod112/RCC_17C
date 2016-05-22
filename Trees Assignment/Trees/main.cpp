/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: mdiaz
 *
 * Created on May 20, 2016, 9:04 AM
 */

#include <cstdlib>
#include <list>
#include <iostream>
#include "TreeNode.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    TreeNode node(3);
    node.setLevel(0);
    node.setData(0);
    node.addChild(1);
    node.addChild(2);
    node.addChild(3);
    cout << "Insert: " << node.insertData(4,1) << endl;
    cout << "Insert: " << node.insertData(5,1)<< endl;
    cout << "Insert: " << node.insertData(6,1)<< endl;
    cout << "Insert: " << node.insertData(7,1)<< endl;
    cout << "Insert: " << node.insertData(8,1)<< endl;
    cout << "Insert: " << node.insertData(9,1)<< endl;
    cout << "Insert: " << node.insertData(10,1)<< endl;
    cout << "Insert: " << node.insertData(11,1)<< endl;
    cout << "Insert: " << node.insertData(12,1)<< endl;
    cout << "Insert: " << node.insertData(13,2)<< endl;
    cout << "Insert: " << node.insertData(14,2)<< endl;
    
    list<TreeNode*>::iterator tempNodeIterator = node.getChildren()->begin();
    
    cout << "Node Data: " << node.getData() << endl;
    
//    while(tempNodeIterator != node.getChildren()->end())
//    {
//        cout << "Node Data: " << (*tempNodeIterator)->getData() << endl;
//        tempNodeIterator++;
//    }
    
    node.printChildren();
    
    return 0;
}

