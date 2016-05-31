/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AVLTree.cpp
 * Author: mario
 * 
 * Created on May 30, 2016, 2:21 PM
 */

#include "AVLTree.h"
#include <string>

using namespace std;

AVLTree::AVLTree() {
    this->root = 0;
}

AVLTree::AVLTree(AVLTree& orig) {
    this->root = orig.root;
}

int AVLTree::height(AVLTreeNode* node)
{
    if(node == 0)
        return -1;
    else
        return max(height(node->getLeft()), height(node->getRight())) + 1;
}

void AVLTree::insert(int data)
{
    if(root == 0)
    {
        root = new AVLTreeNode(data, 0);
    }
    else
    {
        AVLTreeNode* temp = root;
        
        while(1)
        {
            if(temp->getData() == data)//no duplicates
                return;
            
            if(temp->getData() > data)//insert left
            {
                if(temp->getLeft() == 0)
                {
                    AVLTreeNode* newNode = new AVLTreeNode(data, temp);
                    temp->setLeft(newNode);
                    balance(temp);
                    return;
                }
                else
                {
                    temp = temp->getLeft();
                }
            }
            else//insert right
            {
                if(temp->getRight() == 0)
                {
                    AVLTreeNode* newNode = new AVLTreeNode(data, temp);
                    temp->setRight(newNode);
                    balance(temp);
                    return;
                }
                else
                {
                    temp = temp->getRight();
                }

            }
        }
    }
}

void AVLTree::balance(AVLTreeNode* node)
{
    node->setBalance(height(node->getLeft()) - height(node->getRight()));
    
    if(node->getBalance() == 2)
    {
        if(height(node->getLeft()->getLeft()) >= height(node->getLeft()->getRight()))
        {
            node = rightRotate(node);
        }
        else
        {
            node = leftRightRotate(node);
        }
    }
    else if(node->getBalance() == -2)
    {
        if(height(node->getRight()->getRight()) >= height(node->getRight()->getLeft()))
        {
            node = leftRotate(node);
        }
        else
        {
            node = rightLeftRotate(node);
        }
    }
    
    if(node->getParent() != 0)
        balance(node->getParent());
    else
        root = node;
}

AVLTreeNode* AVLTree::leftRotate(AVLTreeNode* node)
{
    AVLTreeNode* temp = node->getRight();
    
    //move temp node up
    temp->setParent(node->getParent());
    
    //move temp left child
    node->setRight(temp->getLeft());
    
    //update child parent
    if(node->getRight() != 0)
        node->getRight()->setParent(node);
    
    //move temp node down
    temp->setLeft(node);
    node->setParent(temp);
    
    //update parent
    if(temp->getParent() != 0)
    {
        if(temp->getParent()->getRight() == node)
            temp->getParent()->setRight(temp);
        else
            temp->getParent()->setLeft(temp);
    }
    
    node->setBalance(height(node->getLeft()) - height(node->getRight()));
    temp->setBalance(height(temp->getLeft()) - height(temp->getRight()));
}

AVLTreeNode* AVLTree::rightRotate(AVLTreeNode* node)
{
    AVLTreeNode* temp = node->getLeft();
    
    //move temp node up
    temp->setParent(node->getParent());
    
    //move temp left child
    node->setLeft(temp->getRight());
    
    //update child parent
    if(node->getLeft() != 0)
        node->getLeft()->setParent(node);
    
    //move temp node down
    temp->setRight(node);
    node->setParent(temp);
    
    //update parent
    if(temp->getParent() != 0)
    {
        if(temp->getParent()->getRight() == node)
            temp->getParent()->setRight(temp);
        else
            temp->getParent()->setLeft(temp);
    }
    
    node->setBalance(height(node->getLeft()) - height(node->getRight()));
    temp->setBalance(height(temp->getLeft()) - height(temp->getRight()));
}

AVLTreeNode* AVLTree::leftRightRotate(AVLTreeNode* node)
{
    node->setLeft(leftRotate(node->getLeft()));
    return rightRotate(node);
}

AVLTreeNode* AVLTree::rightLeftRotate(AVLTreeNode* node)
{
    node->setLeft(rightRotate(node->getRight()));
    return leftRotate(node); 
}

void AVLTree::remove(int data)
{
    remove(data,root);
}

void AVLTree::remove(int data, AVLTreeNode* start)
{
    if(root == 0)
        return;
    
    AVLTreeNode* temp = start;
    
    while(1)
    {
        if(temp->getData() == data)
            break;
        else
        {
            if(data > temp->getData())
            {
                if(temp->getRight() != 0)
                    temp = temp->getRight();
                else
                    return;
            }
            else
            {
                if(temp->getLeft() != 0)
                    temp = temp->getLeft();
                else
                    return;
            }
        }
    }
    
    if(temp == root)//root
    {
        //replace node with smallest value the delete smallest value
        if(temp->getRight() != 0)
        {
            temp->setData(findMin(temp->getRight()));
            remove(temp->getData(), temp->getRight());
        }
        else if(temp->getLeft() != 0)
        {
            temp->setData(findMax(temp->getLeft()));
            remove(temp->getData(), temp->getLeft());
        }
        else
        {
            root = 0;
        }
    }
    else if(temp->getLeft() == 0 && temp->getRight() == 0)//delete leaf
    {
        if(temp->getParent()->getRight() == temp)
        {
            temp->getParent()->setRight(0);
        }
        else
            temp->getParent()->setLeft(0);
        
        temp->~AVLTreeNode();
    }
    else if(temp->getRight() == 0)//has node on left
    {
        AVLTreeNode* tempNode = temp->getLeft();
        AVLTreeNode* tempParent = temp->getParent(); 
        
        if(tempParent->getRight() == temp)
        {
            tempParent->setRight(tempNode);
        }
        else
        {
            tempParent->setLeft(tempNode);
        }
    }
    else if(temp->getLeft() == 0)//has node on right
    {
        AVLTreeNode* tempNode = temp->getRight();
        AVLTreeNode* tempParent = temp->getParent(); 
        
        if(tempParent->getRight() == temp)
        {
            tempParent->setRight(tempNode);
        }
        else
        {
            tempParent->setLeft(tempNode);
        }
    }
    else//full node
    {
        temp->setData(findMin(temp->getRight()));
        remove(data,temp->getRight());
    }
    
    balance(temp);
}
 int AVLTree::findMin(AVLTreeNode* node)
{
     AVLTreeNode* minTemp = node;
     
     while(1)
     {
         if(minTemp->getLeft() == 0)
             return minTemp->getData();
         else
             minTemp = minTemp->getLeft();
     }
}

int AVLTree::findMax(AVLTreeNode* node)
{
     AVLTreeNode* maxTemp = node;
     
     while(1)
     {
         if(maxTemp->getRight() == 0)
             return maxTemp->getData();
         else
             maxTemp = maxTemp->getRight();
     }
}

string AVLTree::toStringInOrder()
{
    if(root != 0)
        return root->toStringInOrder();
    else
        return "";
}
string AVLTree::toStringPreOrder()
{
     if(root != 0)
        return root->toStringPreOrder();
    else
        return "";   
}
string AVLTree::toStringPostOrder()
{
    if(root != 0)
        return root->toStringPostOrder();
    else
        return "";
}
AVLTree::~AVLTree() {
}

