#include <iostream>
#include <vector>

//template <typename T>
using namespace std;

class Sorter {

public:

    void sort(vector<int>& data) {

        // Implementation using a sorting algorithm like quicksort

        for (int i = 0; i < data.size() - 1; ++i) {

            for (int j = i + 1; j < data.size(); ++j) {

                if (data[i] > data[j]) {

                    swap(data[i], data[j]);

                }

            }

        }

    }

};



int main() {

    vector<int> numbers { 5, 2, 8, 1, 3 };

    Sorter sorter;

    sorter.sort(numbers);

    

    for (int num : numbers) {

        cout << num << " ";

    }

    cout << '\n';



    return 0;

}
