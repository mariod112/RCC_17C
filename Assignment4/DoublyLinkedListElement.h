/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DoublyLinkedListElement.h
 * Author: mario
 *
 * Created on April 2, 2016, 12:58 PM
 */

#ifndef DOUBLYLINKEDLISTELEMENT_H
#define DOUBLYLINKEDLISTELEMENT_H

template <class T>
struct DoublyLinkedListElement
{
    DoublyLinkedListElement<T> *next;
    DoublyLinkedListElement<T> *previous;
    T data;
};



#endif /* DOUBLYLINKEDLISTELEMENT_H */

