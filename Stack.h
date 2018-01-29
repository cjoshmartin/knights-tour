//
// Honor Pledge:
//
// I pledge that I have neither given nor
//  received any help on this assignment.
//
//chajmart

//

#ifndef KNIGTHS_TOURS_STACK_H
#define KNIGTHS_TOURS_STACK_H


#include "State.h"

class Stack {
public:
    Stack();
    virtual ~Stack();
    void pop();
    State top();

private:
    State * currentState;
};


#endif //KNIGTHS_TOURS_STACK_H
