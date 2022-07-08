//Erkin Aydın 22002956
#ifndef ASSIGNMENT_4_STACK_H
#define ASSIGNMENT_4_STACK_H

#include <iostream>
using namespace std;
template<typename StackItem>

class Stack {
public:
    Stack();
    Stack(Stack& aStack);
    ~Stack();

    bool isEmpty();
    bool push(StackItem newNumber);
    bool pop(); // Remove
    bool pop(StackItem& stackTop); //Retrieve and remove
    bool getTop(StackItem&  stackTop); //Retrieve

private:
    struct StackNode{
        StackItem item;
        StackNode* next;
    };

    StackNode* topPtr;
};


#endif //ASSIGNMENT_4_STACK_H
