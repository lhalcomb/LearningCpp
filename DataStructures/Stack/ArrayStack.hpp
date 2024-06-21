#ifndef ARRAYSTACK_HPP
#define ARRAYSTACK_HPP

#include<iostream>
#include<string> 

class Stack{

    private: 
        
        int top;
        static int arr[];
    
    public:
        Stack();
        static const int maxSize = 1000;
        void push(int val);
        int pop();
        int peek(int pos);
        int count();
        bool isEmpty();
        bool isFull();
};

#endif