//
// Honor Pledge:
//
// I pledge that I have neither given nor
//  received any help on this assignment.
//
//chajmart

//

#include "Stack.h"

Stack::Stack(): _size(0) {

}

template<typename T>
Stack<T>::Stack(T *item): _size(1), _head(item) {}

Stack::~Stack() {
    clear();
}

template<typename T>
void Stack<T>::pop() {

    if (is_empty())
        throw Stack::empty_exception();

    T * to_remove = _head;
    T * will_be_head = _head->next;

    delete to_remove;
    _head = will_be_head;
    _size--;

    if (_size < 0)
        _size = 0;
}

template<typename T>
T Stack<T>::top() {

    return this->_head;
}

template<typename T>
void Stack<T>::push(T * item) {
    item->next = _head;
    _head = item;
    _size++;
}

template<typename T>
bool Stack<T>::is_empty(void) const {

    return this->_size == 0;
}

template<typename T>
size_t Stack<T>::size(void) const {

    return this->_size;
}

template<typename T>
void Stack<T>::clear(void) {

    for (int i = 0; i < _size; ++i) {
        pop();
    }
}

