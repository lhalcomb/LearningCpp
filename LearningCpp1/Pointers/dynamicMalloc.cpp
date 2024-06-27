#include <iostream> 
using namespace std;

int main(){
    int *int_ptr = nullptr;
    int_ptr = new int; // allocate an integer on the heap
    cout << int_ptr << endl; // some memory
    cout << *int_ptr << endl; //some garbage
    *int_ptr = 5; // set the value of the integer to 5
    cout << *int_ptr << endl; // 5
    delete int_ptr; // deallocates the memory

    /*
    What is the memory heap? 
    According to this course given at University of Illinois - Urbana Champagne, CS 225,
    heap memory is allocated explicitly by programmers and it won’t be deallocated until it is explicitly freed.

    The first time I learned about this, it was the hard way. 
    */

   //example 

   int *array_ptr {nullptr}; 
   int size; 

   cout << "How big should the array be? " << cin >> size << endl; 
   array_ptr = new int[size]; // allocate an array of size on the heap
   delete[] array_ptr;
}