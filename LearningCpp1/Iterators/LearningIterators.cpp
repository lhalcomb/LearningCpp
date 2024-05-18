#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
    An iterator is an object that allows you to traverse through 
    a sequence of elements, one by one. 

    i.e. 
    In python we have "for 'i' in range():,
    in java we have "for (int 'i' = 0; boolean; step) & so on...
 */

void vectorIterator()
{
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    vector<int>::iterator it;
    it = numbers.begin();

    //cout << &it << endl;
    cout << *it << endl;

    it++;
    cout << *it << endl;
    ++ it;
    cout << *it << endl;

    it = numbers.begin();

    while (it < numbers.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << "~While Loop" << endl;

    it = numbers.begin();

    for ( it = numbers.begin(); it < numbers.end(); it++){
        cout << *it << " ";
    }
    cout << "~For loop" << endl;


}

void unordered_mapIterator(){
    unordered_map<string, int> fruits;

    fruits["Apples"] = 5;
    fruits["Oranges"] = 10;
    fruits["Bananas"] = 15;
    fruits["Pears"] = 20;
    fruits["Grapes"] = 25;

    unordered_map<string, int>::iterator it;

    for (it = fruits.begin(); it!= fruits.end(); it++)
    {
        cout << "Fruit: " << it ->first << ", Amount: " << it -> second << endl;
    }

}

unordered_map<int, string> inversedMap(const unordered_map<string, int>& originalUnorderedMap)
{
    unordered_map<int, string> inversedMap;

    for (const auto& kv : originalUnorderedMap){
        inversedMap[kv.second] = kv.first;
    }

    return inversedMap;
}

int main(){
    cout << "Vector Iterator Example: " <<endl;
    vectorIterator();
    cout << endl << "Unordered Map Iterator Example: " << endl;
    unordered_map<string, int> fruits;

    fruits["Apples"] = 5;
    fruits["Oranges"] = 10;
    fruits["Bananas"] = 15;
    fruits["Pears"] = 20;
    fruits["Grapes"] = 25;


    unordered_mapIterator();

    cout << endl << " Inversed Map Example: " <<endl;
    unordered_map<int, string> invertedMap = inversedMap(fruits);
    
    for (const auto& kv : invertedMap){
        cout << "Amount: " << kv.first << ", Fruit: " << kv.second << endl;
    }
    
    return 0;
}