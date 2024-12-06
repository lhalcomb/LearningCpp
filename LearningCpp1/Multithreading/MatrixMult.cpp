//Parallel Processing Rows for matrix multiplication

/*In large matrix operations, 
each row or chunk of the matrix can be processed in parallel.*/

//This is how your pytorch library does it lol

#include <iostream>
#include <vector>
#include <thread>

using namespace std;


void multiplyRow(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int row) {
    int n = B[0].size();
    for (int col = 0; col < n; ++col) {
        C[row][col] = 0;
        for (int k = 0; k < A[0].size(); ++k) {
            C[row][col] += A[row][k] * B[k][col];
        }
    }
}

int main() {
    vector<vector<int>> A = {{1, 2}, {3, 4}};
    vector<vector<int>> B = {{5, 6}, {7, 8}};
    vector<vector<int>> C(2, vector<int>(2, 0));

    vector<thread> threads;
    for (int i = 0; i < A.size(); ++i) {
        threads.push_back(thread(multiplyRow, cref(A), cref(B), ref(C), i));
    }

    for (auto& t : threads) {
        t.join();
    }

    cout << "Resultant Matrix C:\n";
    for (const auto& row : C) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}

