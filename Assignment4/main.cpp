/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: mario
 *
 * Created on March 28, 2016, 8:03 PM
 */

#include <cstdlib>


#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"
#include "PriorityQueue.h"
#include "SortedLinkedList.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

   Stack<int> testStack(0);
   Queue<int> testQueue(0);
   DoublyLinkedList<int> doublyLinkedList(0);
   CircularLinkedList<int> circularLinkedList(0);
   PriorityQueue<int> priorityQueue(0,0);
   SortedLinkedList<int> sortedLinkedList(0);
   
   cout <<endl<< "---------------------Test Queue------------------------"<<endl;
      
   for(int i = 1; i < 10; i++)
   {
       testStack.push(i);  
   }
   
   for(int i = 0; i < 10; i++)
   {
        cout << "Peek Value: " << testStack.peek() << endl;
        cout << "Value: " << testStack.pop() << endl;  
   }
  
   cout <<endl<< "---------------------Test Queue------------------------"<<endl;
   
   for(int i = 1; i < 10; i++)
   {
       testQueue.push(i);
   }
   
   for(int i = 0; i < 9; i++)
   {
        cout << "Peek Value: " << testQueue.peek() << endl;
        cout << "Value: " << testQueue.next() << endl;  
   }
   
  
   cout <<endl<< "---------------------Test DoublyLinkedList------------------------"<<endl;
   
   for(int i = 1; i < 10; i++)
   {
       doublyLinkedList.push_back(i);  
   }
   
   for(int i = 0; i < 10; i++)
   {
        cout << "Peek Value: " << doublyLinkedList.GetCurrent()->data << endl;
        cout << "Value: " << doublyLinkedList.MoveToNext()->data << endl;  
   }
   
   for(int i = 0; i < 9; i++)
   {
        cout << "Value: " << doublyLinkedList.MoveToLast()->data << endl;  
   }
   
   for(int i = 0; i < 9; i++)
   {
       doublyLinkedList.pop_off(); 
   }
 
   
   cout <<endl<< "---------------------Circular Linked List------------------------"<<endl;
   
   for(int i = 1; i < 10; i++)
   {
       circularLinkedList.push_back(i);
   }
   
   for(int i = 0; i < 20; i++)
   {
        cout << "Value: " << circularLinkedList.GetNext()->data << endl;  
   }
   
   cout <<endl<< "---------------------Priority Queue------------------------"<<endl;
   
   for(int i = 1; i < 10; i++)
   {
       priorityQueue.insert(i, i);
   }
   
   for(int i = 0; i < 10; i++)
   {
       cout<< "Priority: " << priorityQueue.GetCurrentPriority() << endl;
       cout << "Value: " << priorityQueue.next() << endl;  
   }
   
    
   cout <<endl<< "---------------------Sorted Linked List------------------------"<<endl;
   
   for(int i = 0; i  < 10; i++)
   {
       sortedLinkedList.push_back(i);
   }
   
   sortedLinkedList.push_back(5);
   sortedLinkedList.push_back(1);
   
   for(int i = 0; i < 13; i++)
   {
       cout << "Value: " << sortedLinkedList.pop_off() << endl;  
   }
       
   return 0;
}

