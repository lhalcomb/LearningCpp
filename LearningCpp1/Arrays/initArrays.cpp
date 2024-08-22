#include <iostream>

using namespace std;

int arr[5] = { 1, 2, 3, 4, 5 }; //This is how you would declare a list of 5 elements

int main(){
    /* for (int i = 0; i < 5; i++){
        std::cout <<i;
    }

    int arr[5]; */

    char a = 'A';
    a++;
    std::cout << static_cast<int>(a);
    std::cout <<static_cast<char>(a);
}

