#include <iostream>

int main()
{

    /*Arithmetic Operands:
    +
    -
    /
    %
    *
    
    */

    int x = 123;
    int y = 456; 
    int z = x + y;
    z = x - y;
    z = x * y;
    z = x / y;

    std::cout<< "The value of z is: " <<z<< '\n';

    // We could use a float type such as 'double' to imoply the decimal form of such variable

    double x1 = 350;
    double y1 = 60; 
    double z1 = x1/y1;

    std::cout <<"The value of z is now : "<<z1 << '\n';

    /* Arithmetic Compoud Operands: 
        += -= *= /= %= 
    */

   int x2 = 123;
   x2 += 10;
   x2 -= 10;
   x2 *= 2;
   x2 /= 3;
   x2 %= 7;

   //All of these compounded operands are the same as (new_variable) = (other_variable) (operand; + - * % /) (number)

/*  
increment operators:

++x 
x++

decrement operators:

--x
x--

These will be helpful later in learning for and while loops

*/ 



}