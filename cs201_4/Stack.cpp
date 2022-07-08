//Erkin Aydın 22002956

#include "Stack.h"
#include <iostream>
using namespace std;


template <typename StackItem>
Stack<StackItem>::Stack() {
    topPtr = NULL;
}

template <typename StackItem>
Stack<StackItem>::Stack(Stack &aStack) {
    if(aStack.topPtr == NULL) {
        topPtr = NULL;
    }
    else {
        topPtr = new StackNode;
        topPtr->item = aStack.topPtr->item;

        //Another pointer is required to form the newly created linked list
        StackNode* newPtr = topPtr;
        for(StackNode* origPtr = aStack.topPtr->next; origPtr != NULL; origPtr = origPtr->next) {
            newPtr->next = new StackNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }
        newPtr->next = NULL;
    }
}
template <typename StackItem>
Stack<StackItem>::~Stack() {
    while(!isEmpty()){
        pop();
    }
}
template <typename StackItem>
bool Stack<StackItem>::isEmpty() {
    if(topPtr == NULL) {
        return true;
    }
    else {
        return false;
    }
}
template <typename StackItem>
bool Stack<StackItem>::push(StackItem newNumber) {
    //What if it is not a number???
    StackNode* newPtr = new StackNode;
    newPtr->item = newNumber;
    newPtr->next = topPtr;
    topPtr = newPtr;
    return true;
}
// Only removes.
template <typename StackItem>
bool Stack<StackItem>::pop() {
    if(isEmpty()) {
        return false;
    }
    else {
        StackNode* temp = topPtr;
        topPtr = topPtr->next;
        temp->next = NULL; //Just to be safe
        delete temp;
        return true;
    }
}

//Retrieves and removes at the same time.
template <typename StackItem>
bool Stack<StackItem>::pop(StackItem& toPop) {
    if(isEmpty()) {
        return false;
    }
    else {
        StackNode* temp = topPtr;
        topPtr = topPtr->next;
        temp->next = NULL; //Just to be safe
        toPop = temp->item;
        delete temp;
        return true;
    }
}

//Only retrieves.
template <typename StackItem>
bool Stack<StackItem>::getTop(StackItem& stackTop) {
    if(isEmpty()) {
        return false;
    }
    else {
        stackTop = topPtr->item;
        return true;
    }
}

template class Stack <string>;
template class Stack <double>;