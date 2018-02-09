//
// Honor Pledge:
//
// I pledge that I have neither given nor
//  received any help on this assignment.
//
//chajmart

//

// NOTE: T <==> postion class

#include "Stack.h"

Stack::Stack(): _size(0) {

}

Stack::Stack(postion *item): _size(1), _head(item) {}

Stack::~Stack() {
    clear();
}

void Stack::pop() {

    if (is_empty())
        throw Stack::empty_exception();

    postion * to_remove = _head;
    postion * will_be_head = _head->next;

    delete to_remove;
    _head = will_be_head;
    if(_size > 0)
        _size--;
}

postion * Stack::top() {

    return this->_head;
}

void Stack::push(postion * item) {
    item->next = _head;
    _head = item;
    _size++;
}

bool Stack::is_empty(void) const {

    return this->_size == 0;
}

size_t Stack::size(void) const {

    return this->_size;
}

void Stack::clear(void) {

    for (int i = 0; i < _size; ++i) {
        pop();
    }
}

