/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Queue.h
 * Author: mario
 *
 * Created on April 2, 2016, 12:29 PM
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
#include <string.h>

#include "LinkedListElement.h"

template <class T>
class Queue
{
private:
   ListElement<T> *head;
   ListElement<T> *tail;
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range
   
public:
   // Default constructor
   Queue()
   {
       head = new ListElement<T>;
       head->pointer = 0;
       head->data = 0;
       tail = head;
   }
      
   // Constructor declaration
   Queue(T);
   
   // Copy constructor declaration
   Queue(const Queue<T> &);
   
   // Destructor declaration
   ~Queue();
   T peek();
   // Overloaded [] operator declaration
   T &operator[](const int &);
   void Purge();
   void push(T);
   T next();
};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
Queue<T>::Queue(T data)
{
       head = new ListElement<T>;
       head->pointer = 0;
       head->data = data;
       tail = head;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
Queue<T>::Queue(const Queue<T> &obj)
{
    this->head = obj->head;
    this->tail = obj->tail;
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
Queue<T>::~Queue()
{
    Purge();
    
    delete head;
    delete tail;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void Queue<T>::memError()
{
   //cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void Queue<T>::subError()
{
   //cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

template <class T>
void Queue<T>::Purge()
{
    
    while(head != NULL)
    {
        ListElement<T>* temp = head;
        head = head->pointer;
        delete temp;
    }
    
    tail = NULL;
    
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************
template <class T>
T Queue<T>::peek()
{
    if(head != NULL)
        return head->data;
    else
        return 0;
}

template <class T>
void Queue<T>::push(T value)
{
    ListElement<T>* temp = new ListElement<T>;
    temp->pointer = NULL;
    temp->data = value;
    
    if(head != NULL)
    {
        if(tail != NULL)
        {
            tail->pointer = temp;
        }
        else
            head->pointer = temp;
        
        tail = temp;
    }
    else
    {
        head = temp;
    }
}

template <class T>
T Queue<T>::next()
{
    T tempValue;
    
    if(head->pointer != tail)
    {
        ListElement<T>* temp = head;
        tempValue = head->data;
        head = head->pointer;
        delete temp;
    }
    else
    {
        tempValue = tail->data;
        tail = NULL;
        head = NULL;
    }
    
    return tempValue;
}
#endif /* QUEUE_H */

