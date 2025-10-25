#include <iostream>
#include <cassert> 
#include "LinkedList.h"


// Stack is a LinkedList but with LIFO 
// implemention with push/poFront: in this way the last element is always head so O(1)
template <typename T> class Stack{
    private:
        LinkedList<T> list; 
    public:
        void push(const T& value){list.pushfront(value);}
        void pop () {list.popFront();}
        T& top() { return list[0]; }        
        bool isEmpty() const { return list.getLength() == 0; }
        void print() const {list.print();}
};