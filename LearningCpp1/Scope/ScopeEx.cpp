#include <iostream>
#include <vector>
#include <string>


int fun(int *a){
    
    (*a)++;
    
    return *a;
}

int a = 5; 
int fun1(){
    a = 17;
    return 3; 
}
int main() {
    const double PI = 3.14159;

    //PI = 3;

    std::cout << PI << std::endl;

    std::vector<int> list = {1, 2, 3};
    int a = list[1];
    float b = static_cast<float>(a);

    std::string greeting = "Hello";

    //greeting = 1; 

    std::cout << greeting << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

     /*int a = 10;
   
   int b = a + fun(&a);
   
   int b1 = fun(&a) + a;
   
   std::cout << a << std::endl;
   std::cout << b << std::endl;
   std::cout << b1 << std::endl;*/
   
   int a = a + fun1();
   std::cout << a << std::endl;
   //int a1 = fun1() + a;
   //std::cout << a1 << std::endl;

}
