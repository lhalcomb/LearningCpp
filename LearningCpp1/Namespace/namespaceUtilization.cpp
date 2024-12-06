#include <iostream> //including a header file for input and output stream to the console/terminal

using namespace std; 
// stating the namespace of the std (Standard Library) shall be used
//this way i dont have to inherit it every time i use it. i.e. no std::cout or std::cin

namespace first_block
{
    //notice, no semicolon. Similar to header syntax, or function syntax
    void func(){
        cout << "Hello, World from the first block!" << endl;
    }
}


namespace second_block
{
    void func(){
        cout << "Hello, World from the second block!" << endl;
    }
}

using namespace first_block; //JUST LIKE USING NAMESPACE STD
int main(){
    func(); //calling the function from the first block
}



