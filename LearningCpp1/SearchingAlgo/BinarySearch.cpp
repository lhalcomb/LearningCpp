#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class SearchAlgorithms {
public:
    int binarySearch(vector<int>& list, int target) {
        cout  << "Binary search in progress..." << endl;
        int left = 0; 
        int right = list.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (list[mid] == target){
                return mid;
            } else if (list[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1; // Element not found
    }

    int  linearSearch(int *arr, int size, int element) {
        cout  << "Linear search in progress..." << endl;

        for (int i = 0; i < size; i++){
            if  (arr[i] == element){
                return i;
            }
        }
        return -1;
    }
};

int main() {
    SearchAlgorithms searchAlgos;

    
     vector<int> list;
    
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(7);
    list.push_back(9);

    int target1 = 3;

    int result = searchAlgos.binarySearch(list, target1);
    if (result == -1) {
        cout << "Element is not present in the array" << endl;
    } else {
        cout << "Element is present at index " << result << endl;
    }

    int arr[] = {1, 3, 5, 7, 9};
    int target2 = 9;
    int size = sizeof(arr)/sizeof(arr[0]);
    int resLin = searchAlgos.linearSearch(arr, size, target2);

    if (resLin == -1) {
        cout << "Element is not present in the array" << endl;
    } else {
        cout << "Element is present at index " << resLin << endl;
    }




    return 0;
}
