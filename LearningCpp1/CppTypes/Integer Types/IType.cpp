#include <iostream>

int main()
{
    
    //Integer Types
    std::cout<<"Integer Types: "<<std::endl;
    unsigned int x = 123;
    int y = -246;
    std::cout <<"The value of x is: " <<x<< ", the value of y is : " << y<<std::endl;

    //You can also intitialize a varialbe with another variable. For instance below we have,

    int a = 45;
    int b = a;
    std::cout <<"\nThe values of a and b are: " <<a<<" and "<<b;
    //a is 45
    //b is also 45
    a = 35; 
    std::cout << "\na has been changed to: " <<a<< " \nb still equals: " <<b<<std::endl;

    /* There also exist integer literals. These consists of integer types that are decimal, octal, and hexadecimal. 
    Octaliterals start with a prefix of 0, and hexadecimals begin with a prefix of 0x.
    There is also integer types such as int64_t and more but I am only learning the basics for now lol.
    */

    int c = 10; //decimal literal
    int d = 012; //octal literal
    int e = 0XA; //hexadecimal literal

    return 0;
}