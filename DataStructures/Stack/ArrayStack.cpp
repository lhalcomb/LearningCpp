#include "ArrayStack.hpp"

Stack::Stack(){
    top = -1;
    
    for (int = 0; i < maxSize; i++){
        arr[i] = 0;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}
bool Stack::isFull()
{
    return (top >= maxSize - 1);
}

void Stack::push(int val)
{
    if (isFull()){
        std::cout << "Cannot push into stack, Stack Overflow" << std::endl;
    }else{
        top++; // 0
        arr[top] = val; // store val to arr index top == 0
    }
}

int Stack::pop()
{
    if (isEmpty()){
        std::cout << " Stack Underflow" << std::endl;
        return 0;
    }else{
        int popVal = arr[top];
        arr[top] = 0; 
        top--;
        return popValue; 
    }
}

int Stack::count()
{
    return (top+1)
}

int Stack::peek(int pos)
{
    if (isEmpty()){
        std::cout << " Stack Underflow" << std::endl;
        return 0;
    }else{
        return arr[pos];
    }
}