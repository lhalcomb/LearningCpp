#include <iostream>
#include <vector>
#include <string>


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

}
