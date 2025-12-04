#include <iostream>
using namespace std;

const int SIZE = 2;  // Change this for bigger matrices

// Function to perform element-wise OR (Joint)
void booleanJoint(int A[][SIZE], int B[][SIZE], int result[][SIZE]) {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            result[i][j] = A[i][j] | B[i][j];
}

// Function to perform element-wise AND (Meet)
void booleanMeet(int A[][SIZE], int B[][SIZE], int result[][SIZE]) {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            result[i][j] = A[i][j] & B[i][j];
}

// Function to perform Boolean product (AND-OR multiplication)
void booleanProduct(int A[][SIZE], int B[][SIZE], int result[][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; ++k) {
                result[i][j] |= (A[i][k] & B[k][j]);
            }
        }
    }
}

// Helper function to print matrices
void printMatrix(int M[][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j)
            cout << M[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int A[SIZE][SIZE] = {{1, 0}, {1, 1}};
    int B[SIZE][SIZE] = {{0, 1}, {1, 0}};
    int joint[SIZE][SIZE], meet[SIZE][SIZE], product[SIZE][SIZE];

    booleanJoint(A, B, joint);
    booleanMeet(A, B, meet);
    booleanProduct(A, B, product);

    cout << "Matrix A:\n"; printMatrix(A);
    cout << "Matrix B:\n"; printMatrix(B);
    cout << "\nJoint (OR):\n"; printMatrix(joint);
    cout << "Meet (AND):\n"; printMatrix(meet);
    cout << "Boolean Product:\n"; printMatrix(product);

    return 0;
}

