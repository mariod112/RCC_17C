/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CircularLinkedLIst.h
 * Author: mario
 *
 * Created on April 3, 2016, 10:17 AM
 */

#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
#include <string.h>

#include "LinkedListElement.h"

using namespace std;

template <class T>
class CircularLinkedList
{
private:
   ListElement<T> *head;
   ListElement<T> *next;
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range
   
public:
   // Default constructor
   CircularLinkedList()
   {
       head = new ListElement<T>;
       head->pointer = head;
       head->data = 0;
       next = head;
   }
      
   // Constructor declaration
   CircularLinkedList(T);
   
   // Copy constructor declaration
   CircularLinkedList(const CircularLinkedList &);
   
   // Destructor declaration
   ~CircularLinkedList();
   ListElement<T>* GetNext();
   // Overloaded [] operator declaration
   T &operator[](const int &);
   void Purge();
   void push_back(T);
   void pop_off();
};

//***********************************************************
// Constructor for CircularLinkedList class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
CircularLinkedList<T>::CircularLinkedList(T data)
{
       head = new ListElement<T>;
       head->pointer = head;
       head->data = data;
       next = head;
}

//*******************************************
// Copy Constructor for CircularLinkedList class. *
//*******************************************

template <class T>
CircularLinkedList<T>::CircularLinkedList(const CircularLinkedList &obj)
{
    this->head = obj->head;
    this->next = obj->next;
}

//**************************************
// Destructor for CircularLinkedList class.  *
//**************************************

template <class T>
CircularLinkedList<T>::~CircularLinkedList()
{
    Purge();
    delete head;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void CircularLinkedList<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void CircularLinkedList<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

template <class T>
void CircularLinkedList<T>::Purge()
{
    while(head->pointer != next)
    {
        ListElement<T>* temp = head;
        head = head->pointer;
        delete temp;
    }
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &CircularLinkedList<T>::operator[](const int &sub)
{
    ListElement<T>* temp = head;
    int count = sub;
    
    while(temp->pointer != 0)
    {
        if(count == 0)
            break;
        
        temp = temp->pointer;
        count--;
    }
    
    return temp->data;
}

template <class T>
ListElement<T>* CircularLinkedList<T>::GetNext()
{
    ListElement<T>* temp = next;
    
    next = next->pointer;
    
    return temp;
}

template <class T>
void CircularLinkedList<T>::push_back(T value)
{
    ListElement<T>* temp = next;
    
    while(temp->pointer != head)
    {
        temp = temp->pointer;
    }
    
    temp->pointer = new ListElement<T>;
    temp->pointer->data = value;
    temp->pointer->pointer = head;
}

template <class T>
void CircularLinkedList<T>::pop_off()
{
    if(head->pointer != 0)
    {
        ListElement<T>* temp = head;
        head = head->pointer;
        delete temp;
    }
    
}

#endif /* CIRCULARLINKEDLIST_H */

