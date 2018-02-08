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

template <typename T>
class Stack {
public:
    typedef T type;

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
    Stack(T * item);
    virtual ~Stack();
    void pop();
    T top();
    void push(T * item);

    bool is_empty (void) const;
    size_t size (void) const;
    void clear (void);

private:
    T * _head;
    size_t _size;
};


#endif //KNIGTHS_TOURS_STACK_H
