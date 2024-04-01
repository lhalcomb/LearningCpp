#include <iostream>

int main()
{
    unsigned long int x = 4294967295;
    std::cout << "unsigned long: " << sizeof(long) * CHAR_BIT; //<< x; 
}