#include <iostream> 
#include <vector>

using namespace std;

int main(){
    vector<int> vector1;
    vector<int> vector2;

    vector1.push_back(10);
    vector1.push_back(20);

    std::cout << vector1.at(0) << " Vector 1 first index" << '\n';
    std::cout << vector1.at(1) << " Vector 1 second index"<< "\n";

    std::cout<< vector1.size() << " Vector 1 size " << "\n";


    vector2.push_back(100);
    vector2.push_back(200);

    vector<vector<int>> vector_2D;
    vector_2D.push_back(vector1);
    vector_2D.push_back(vector2);

    std::cout <<  "2D Vector elements at the zero index: " << "\n";
    for (size_t i; i < vector_2D.at(0).size(); i++){
        std::cout << vector_2D.at(0).at(i) << ", ";
    }
    std::cout << " \n"; 
    


    vector1.at(0) = 1000;

    std::cout <<  "2D Vector elements at the zero index: " << "\n";
    for (size_t i = 0; i < vector_2D.at(0).size(); i++){
        std::cout << vector_2D.at(0).at(i) << ", ";
    }
    std::cout << " \n"; 

    std::cout << vector1.at(0) << "\n";
    std::cout << vector1.at(1) << "\n";
    std::cout << "The 2D Vectors elements: " << "\n";
    for (size_t i = 0; i < vector_2D.size(); i++){
        for (size_t j = 0; j < vector_2D[i].size(); j++){
            std::cout << vector_2D[i][j] << ", ";
        }

        std::cout << "\n";
    }

    return 0;

}