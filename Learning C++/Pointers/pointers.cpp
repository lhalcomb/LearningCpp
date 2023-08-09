#include <iostream>

int main()
{
    int* p;
    char* q;
    /*These are pointers of variable types that point to a certain object in memory just like variables
      Unlike variables, pointers are types that can hold the address of a particular object.
    */

   int x = 123;
   int* n = &x; //This points to the existing object in memory denoted as x. We use the address-of operator &, and say that n points to x

   char* c = nullptr; //This declares a pointer variable of a specified empty spot in memory

   std::cout<< "The value of the dereferenced pointer is: " <<*n << '\n'; 

   *n = x * 2;
   std::cout <<"The value of the dereferenced pointer is now: " <<*n;
}