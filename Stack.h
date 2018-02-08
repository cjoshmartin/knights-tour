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


#include <exception>
#include "postion.h"

class Stack {
public:

    /**
     * @class empty_exception
     *
     * Exception thrown to indicate the stack is empty.
     */
    class empty_exception : public std::exception
    {
    public:
        /// Default constructor.
        empty_exception (void)
                : std::exception () {
        }

    };

    Stack();
    Stack(postion * item);
    virtual ~Stack();
    void pop();
    postion * top();
    void push(postion * item);

    bool is_empty (void) const;
    size_t size (void) const;
    void clear (void);

private:
    postion * _head;
    size_t _size;
};


#endif //KNIGTHS_TOURS_STACK_H
