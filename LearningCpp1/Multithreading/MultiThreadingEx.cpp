#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

int binarySearch(vector<int> list, int low, int high, int elementToFind ){
    
    while(low <= high){
        int mid = low + (high - low)/2; // get the middle
        if(list[mid] == elementToFind){// if elementToFind is present at mid
            return mid;
        }else if (list[mid] > elementToFind){ // if element to find is less than the mid, then move the high to the middle - 1
            high = mid - 1;
        }else if (list[mid] < elementToFind){// if element to find is greater than the mid, then move the low to the middle  + 1
            low = mid + 1;
        }
    }

    return -1;
}

void threadedBinarySearch(vector<int> list, int low, int high, int elementToFind, int* result){
    *result = binarySearch(list, low, high, elementToFind);
}

vector<int> randomNumberGen(int sizeOfList){
    vector<int> randomList;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    for (int i = 0; i < sizeOfList; ++i){
        randomList.push_back(dis(gen));
    }

    return randomList;
}


int main(){

    int sizeOfList = 1000000;
    vector<int> list = randomNumberGen(sizeOfList); 
    int elementToFind = 42;
    sort(list.begin(), list.end());
    int mid = list.size() / 2;
    int result1 = -1, result2 = -1;


    auto startThreaded = high_resolution_clock::now();
    thread t1(threadedBinarySearch, list, 0, mid - 1, elementToFind, &result1);
    thread t2(threadedBinarySearch, list, mid, list.size() - 1, elementToFind, &result2);

    t1.join();
    t2.join();
    auto stopThreaded = high_resolution_clock::now();
    auto durationThreaded = duration_cast<microseconds>(stopThreaded - startThreaded);


    //Checking Multiple Threads
    if (result1 != -1) {
        cout << "Element is present at index " << result1 << " (Thread 1 result)" << endl;
    } else if (result2 != -1) {
        cout << "Element is present at index " << result2 << " (Thread 2 result)" << endl;
    } else {
        cout << "Element is not present in the list" << endl;
    }
    cout << "Threaded binary search took " << durationThreaded.count() << " microseconds.\n";


    //Single Thread!

    auto startSingle = high_resolution_clock::now();
    int result = binarySearch(list, 0, list.size() - 1, elementToFind);
    auto endSingle = high_resolution_clock::now();
    auto singleDuration = duration_cast<microseconds>(endSingle - startSingle);

    if (result != -1) {
        cout << "Element found at index " << result << " (Single-threaded result)" << endl;
    } else {
        cout << "Element not found in single-threaded search" << endl;
    }

    cout << "Single-threaded binary search took " << singleDuration.count() << " microseconds.\n";

}