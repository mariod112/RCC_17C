/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PriorityQueue.h
 * Author: mario
 *
 * Created on April 5, 2016, 12:29 PM
 */

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
#include <string.h>

#include "PriorityLinkedListElement.h"

template <class T>
class PriorityQueue
{
private:
   PriorityListElement<T> *head;
   PriorityListElement<T> *tail;
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range
   
public:
   // Default constructor
   PriorityQueue()
   {
       head = new PriorityListElement<T>;
       head->pointer = 0;
       head->data = 0;
       head->priority = 0;
       tail = head;
   }
      
   // Constructor declaration
   PriorityQueue(T,int);
   
   // Copy constructor declaration
   PriorityQueue(const PriorityQueue<T> &);
   
   // Destructor declaration
   ~PriorityQueue();
   T peek();
   // Overloaded [] operator declaration
   T &operator[](const int &);
   void Purge();
   void insert(T,int);
   T next();
   int GetCurrentPriority();
};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
PriorityQueue<T>::PriorityQueue(T data, int priority)
{
       head = new PriorityListElement<T>;
       head->pointer = 0;
       head->data = data;
       head->priority = priority;
       tail = head;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T> &obj)
{
    this->head = obj->head;
    this->tail = obj->tail;
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
PriorityQueue<T>::~PriorityQueue()
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
void PriorityQueue<T>::memError()
{
   //cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void PriorityQueue<T>::subError()
{
   //cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

template <class T>
void PriorityQueue<T>::Purge()
{
    
    while(head != NULL)
    {
        PriorityListElement<T>* temp = head;
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
T PriorityQueue<T>::peek()
{
    if(head != NULL)
        return head->data;
    else
        return 0;
}

template <class T>
int PriorityQueue<T>::GetCurrentPriority()
{
    if(head != NULL)
        return head->priority;
    else
        return 0;
}

template <class T>
void PriorityQueue<T>::insert(T value, int priority)
{
    PriorityListElement<T>* temp = new PriorityListElement<T>;
    temp->data = value;
    temp->priority = priority;
    
    if(head != NULL)
    {
        PriorityListElement<T>*findLast = NULL;
        PriorityListElement<T>* find = head;
        
        while(find->priority >= temp->priority)
        {
            if(find->pointer == NULL)
                break;
            else
            {
                findLast = find;
                find = find->pointer;
            }
        }
        
        if(findLast != NULL)
        {
            findLast->pointer = temp;
            temp->pointer = find;
        }
        else
        {
            temp->pointer = head;
            head = temp;
        }
    }
    else
        head = temp;
    
    /*
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
    }*/
}

template <class T>
T PriorityQueue<T>::next()
{
    T tempValue;
    
    if(head != NULL)
    {
        if(head->pointer != NULL)
        {
            PriorityListElement<T>* temp = head;
            tempValue = head->data;
            head = head->pointer;
            delete temp;
        }
        else if(tail != NULL)
        {
            tempValue = tail->data;
            tail = NULL;
            head = NULL;
        }
    }
    else
        return 0;
    
    return tempValue;
}
#endif /* QUEUE_H */

