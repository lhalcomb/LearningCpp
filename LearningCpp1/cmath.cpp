#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int calculateCircleArea(int radius){
    const double PI = 3.14159265358979323846;

    int area = PI * pow(radius, 2);

    return area;
}

int main(){
    double result1 = floor(1.2);

    double result2 = pow(2, 3);
    cout << result1 <<endl;

    cout << result2 <<endl;
    int radius;
    string input = "Enter the value for radius: ";
    cout << input;
    cin >> radius;
    int result3 = calculateCircleArea(radius);
    cout <<  "The area of the circle is: "<<result3<<endl;

    return 0;

}



