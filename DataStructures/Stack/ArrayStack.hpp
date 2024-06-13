#ifndef ARRAYSTACK_HPP
#define ARRAYSTACK_HPP

#include<iostream>
#include<string> 

class Stack{

    private: 
        static const int maxSize = 1000;
        int top;
        int arr[maxSize];
    
    public:
        Stack();
        void push(int val);
        int pop();
        int peek(int pos);
        int count();
        bool isEmpty();
        bool isFull();
};

#endif