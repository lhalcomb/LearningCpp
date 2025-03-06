#include <iostream>

using namespace std;


// File for helping me automate abstract algebra concepts because I am tired of doing the ideas by hand.
// I will be using the C++ programming language to help me automate the ideas.


//function to count the modulo of a number and retur the quotient * divisor + remainder = dividend

int modulo(int a, int b){
    int dividend = a;
    int divisor = b;

    int quotient = dividend / divisor;
    int remainder = dividend % divisor;

    cout << quotient << " * " << divisor << " + " << remainder << " = " << dividend << endl;


    return 0;
}

//Function to calculate the greatest common divisor of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

//Function to calculate the least common multiple of two numbers
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

//Function to calculate the modular mult. inverse of a number
int modInverse(int a, int m) { //naive way
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

int addInv(int a, int p) { //additive inverse
    return (-a % p + p) % p;
}

int modularInv(int n, int p) { // dynamic programming approach 
    //quick check 
    if (gcd(n, p) != 1) {
        return -1;
    }
    int inv[n + 1];
    inv[0] = inv[1] = 1;
    for ( int i = 2; i <= n; i++){
        inv[i] = inv[p % i] * ( p - p / i) % p;
    }

    for (int i = 0; i <= n; i++) {
        cout << inv[i] << " ";
    }
    cout << endl;

    return 0;
}

int main(){

    int prime = 21;
    for (int i = 0; i < prime; i++) {
        cout << i << " " << modInverse(i, prime) << endl;
    }
    
    modulo(10, 11);

    //the integers mod 9 are 0, 1, 2, 3, 4, 5, 6, 7, 8
    //the addtive inverses are below
    int n = 21;
    for (int i = 0; i < n; i++) {
        cout << i << " " << addInv(i, n) << endl;
    }
    return 0;
}


