#include <iostream> 
#include <bits/stdc++.h> 

template <typename T>

class MyClass{
    private:
        T x;
    public:
         MyClass(T val);
};
template <typename T>
MyClass<T>::MyClass(T val) : x {val}{
    std::cout << "MyClass constructor called with value " << val << std::endl;
}

int main(){
    std::unordered_map<std::string, int> umap;
    umap["apple"] = 10;
    umap["banana"] = 20;
    umap["orange"] = 30;


    MyClass<int> o{1232};
    MyClass<double> o2{ 456.789};
    MyClass<long double> pi {3.1415962};
    
}