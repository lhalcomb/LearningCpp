#include <iostream> 

void swap(int *a, int *b){
    int temp_ptr; //variable initially nothing
    temp_ptr = *a; // nothing variable temp now points to the int at a
    *a = *b; //the int at a now points to the int at b
    *b = temp_ptr; // the integer at b now points to the intialized temp_ptr for a in line 5

//The integers are now considered swapped. 

}

int main(){
    int a = 5, b = 10;

    std::cout << "The variables before the swap" << " The variable a: " << a << " The variable b:" << b << std::endl;
    swap(&a, &b);
    std::cout << "The variables after the swap" << " The variable a: " << a << " The variable b:" << b << std::endl;
   
    return 0; 
}