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
    TreeNode node(1);

    node.addChild(2);
    node.addChild(3);

    list<TreeNode*>::iterator tempNodeIterator = node.getChildren()->begin();
    
    cout << "Node Data: " << node.getData() << endl;
    
    while(tempNodeIterator != node.getChildren()->end())
    {
        cout << "Node Data: " << (*tempNodeIterator)->getData() << endl;
        tempNodeIterator++;
    }
    
    return 0;
}

