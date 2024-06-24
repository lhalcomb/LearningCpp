#include <iostream> 

int main(){
    int favoriteNum;
    std::cout << "Enter your favorite number 0 - 100: ";

    std::cin >> favoriteNum;
    if (favoriteNum == 17){
        std::cout << "That is my favorite number too!" <<std::endl;

    }else{
        std::cout << "There are better numbers" << "\n";
    }
    return 0;

}