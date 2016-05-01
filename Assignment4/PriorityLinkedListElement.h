/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PriorityLinkedListElement.h
 * Author: mario
 *
 * Created on April 5, 2016, 8:21 PM
 */

#ifndef PRIORITYLINKEDLISTELEMENT_H
#define PRIORITYLINKEDLISTELEMENT_H

template <class T>
struct PriorityListElement
{
    PriorityListElement<T> *pointer;
    T data;
    int priority;
};


#endif /* LINKEDLISTELEMENT_H */

