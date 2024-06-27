#include <iostream> 
using namespace std;

int main()
{
    int scores[] {100, 95, 89};
    int *score_ptr {scores}; 

    cout << score_ptr << endl; // Memory - 0x16d45b0e8
    //How do i reference a pointer in an array? 
    cout << score_ptr[0] << endl;
    cout << score_ptr[1] << endl;
    cout << score_ptr[2] << endl; 

    //Like this above 

    //Beginning of pointer arithmetic
    cout << (score_ptr + 1) << endl; // Memory - 0x16d45b0ec
    cout << (score_ptr + 2) << endl; // Memory - 0x16d45b0f0
    //What is the memory doing? Hexadecimal math?

    //Here we move along the array using the pointer. 
    cout << *score_ptr << endl; //100
    cout << *(score_ptr + 1) << endl; // 95
    cout << *(score_ptr + 2) << endl; // 89
   //This is how we dereference the pointer in an array
    

}