#include "ArrayStack.hpp"

using namespace std;
int main()
{
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << stack.pop() << "Popped from stack" << std::endl;

    std::cout << "Top element is " << stack.peek(2) << endl;
    std::cout << "Is stack full? " << stack.isFull() << endl;
    std::cout << "Is stack empty? " << stack.isEmpty() << endl;

    // Fill the stack to demonstrate isFull
    for (int i = 0; i < Stack::maxSize; ++i) {
        stack.push(i);
    }

    cout << "Is stack full after pushing maxSize elements? " << stack.isFull() << endl;
    


    return 0;
    
}