#include <iostream>

using namespace std;

// Function to add two matrices
void addMatrix(int n, int A[][100], int B[][100], int C[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrix(int n, int A[][100], int B[][100], int C[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to perform Strassen's matrix multiplication
void strassenMatrixMultiply(int n, int A[][100], int B[][100], int C[][100]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;
    int A11[100][100], A12[100][100], A21[100][100], A22[100][100];
    int B11[100][100], B12[100][100], B21[100][100], B22[100][100];
    int P1[100][100], P2[100][100], P3[100][100], P4[100][100], P5[100][100], P6[100][100], P7[100][100];
    int C11[100][100], C12[100][100], C21[100][100], C22[100][100];

    // Split the matrices into quadrants
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Calculate the seven products (P1 to P7)
    subtractMatrix(newSize, B12, B22, P1);
    strassenMatrixMultiply(newSize, A11, P1, P2);
    addMatrix(newSize, A11, A12, P3);
    strassenMatrixMultiply(newSize, P3, B22, P4);
    addMatrix(newSize, A22, A21, P5);
    strassenMatrixMultiply(newSize, P5, B11, P6);
    subtractMatrix(newSize, B21, B11, P7);
    strassenMatrixMultiply(newSize, A22, P7, P1);

    // Calculate the four quadrants of the result matrix
    addMatrix(newSize, P5, P4, P3);
    subtractMatrix(newSize, P3, P2, P4);
    addMatrix(newSize, P1, P2, P5);
    subtractMatrix(newSize, P5, P7, P6);

    // Combine the four quadrants to get the result matrix
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = P3[i][j];
            C[i][j + newSize] = P4[i][j];
            C[i + newSize][j] = P5[i][j];
            C[i + newSize][j + newSize] = P6[i][j];
        }
    }
}

int main() {
    int n = 4;
    int A[100][100] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int B[100][100] = {{17, 18, 19, 20}, {21, 22, 23, 24}, {25, 26, 27, 28}, {29, 30, 31, 32}};
    int C[100][100] = {0};

    strassenMatrixMultiply(n, A, B, C);

    cout << "Matrix A:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matrix B:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matrix C (Result of Strassen's Matrix Multiplication):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


   
