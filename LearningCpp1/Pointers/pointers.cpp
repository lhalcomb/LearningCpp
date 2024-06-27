#include <iostream>

using namespace std;

void swapv(int *initial_num, int *new_number){

  int temp;
  cout << " The address of the first variable is: " << &initial_num << endl;
  cout << " The address of the second variable is: " << &new_number << endl;
  temp = *initial_num;
  cout << " The address of temp pointing to the first variable is: " << &temp << endl;
  *initial_num = *new_number;
  cout << " The address of the first variable is: " << &initial_num << endl;
  *new_number = temp;
  cout << " The address of the second variable is: " << &new_number << endl; 

}

void swapInt(int *initial_num, int *new_number){
  int temp;
  temp = *initial_num;
  *initial_num = *new_number;
  *new_number = temp;
}


int main()
{
    int* p;
    char* q;
    /*These are pointers of variable types that point to a certain object in memory just like variables
      Unlike variables, pointers are types that can hold the address of a particular object.
    */

   int num = 123;
   int *num_address = &num; //This points to the existing object in memory denoted as x. We use the address-of operator &, and say that n points to x

   char *anEmptyPointer = nullptr; //This declares a pointer variable of a specified empty spot in memory

   std::cout<< "The value of the dereferenced pointer is: " << *num_address << '\n'; 

   *num_address = num * 2;
   std::cout <<"The value of the dereferenced pointer is now: " << *num_address <<endl;

   int anotherNum = 44;
   int *anotherNum_address;

   string name = "Layden";
   cout << "The variable name holds the string value of: " << name << endl;
   string *name_address = &name;
   cout << "The address of the variable name is: " << name_address << endl;

   //anotherNum_address = &anotherNum;
   //std::cout << "\n " << anotherNum_address <<endl;

   cout << "          " << endl;
   cout << "          " << endl;
   cout << "          " << endl;

   int num1, num2;
   cout << "First Number: ";  cin >> num1;
   cout << "Second Number: "; cin >> num2;
   swapv(&num1, &num2);
   cout << "The size of num1 is: " << sizeof(num1) << " bytes\n "; 
   cout <<"After swapping, first number is : " << num1 <<endl;
   cout << "After  swapping, second number is : " << num2 << endl;

   cout << "          " << endl;
   cout << "          " << endl;
   cout << "          " << endl;

   int score {100}; 
   int *score_ptr = &score;
   cout << "Here is an example of dereferencing: " << endl;
   cout << "The address of score is: " << *score_ptr << endl; 
    cout << "The value of score is: " << score << endl;
   *score_ptr = 200; 
   cout << "The value of score is: " << score << endl;
   cout << "The value of score_ptr is: " << *score_ptr << endl;

   return 0;

}