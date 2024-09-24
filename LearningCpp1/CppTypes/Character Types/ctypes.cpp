#include <iostream>
using namespace std; 

int main()
{
//Character Type
    std::cout<<"Character Types: "<<std::endl;
    char c = 'a';
    std::cout << "\nThe value of our char variable 'c' is: " << c;
    //Variables can be changed. No longer need to redeclare the variable type as long as its type stays consistent
    c = 'Z';
    std::cout <<"\nNow the new value for character 'c' is: " << c ;
    //Here is some object orientation for finding size of the char type
    std::cout << "\nThe size of the type char is: " << sizeof(char)<<" byte(s)" <<std::endl;
    /*There are other character types such as wchar_t for holding characters in Unicode or char16_t for holding UTF-16 character sets. 
    Although in this example there will only be char for now.
    A character literal is a character enclosed with single quotes. i.e. 'a', 'A', 'z', 'X', '0' etc. */
    //Here is an example
    char e = 'a';
    e = 97; //Due to every character literal being represented as an integer, this is the same as 'a'.
    std::cout <<e <<std::endl<<std::endl; 

    char s[20] = "hello";
    std::cout << s << std::endl;
    std::cout << s[21] << std::endl;

    

    return 0;
}

