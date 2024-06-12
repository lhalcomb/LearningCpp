#ifndef  STACK_HPP
#define STACK_HPP

#include <vector>
#include <iostream> 

template <class T> 

/*
    A Stack Data Structure is a data structure than is typically generated in the form of a list. 
That list can be an array, vector, linkedlist, etc. 
For simplicity, this implementation will be done using a vector, for now. In the future, 
it may be changed to be compatible with linked lists too. 

*/

class Stack{
    private:
        std::vector<T> stack;
    public: 

        Stack(){}
        ~Stack(){}

        void push(const T& item){}

        T pop(){

        }

        T peek()
}