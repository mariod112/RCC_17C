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
#include "Tree.h"
#include "TreeNode.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    TreeNode node(3);
    Tree tree(3);
    
    for(int i = 0; i < 100; i++)
    {
        tree.insertData(i);
    }
    
    tree.print();
    
    
    return 0;
}

