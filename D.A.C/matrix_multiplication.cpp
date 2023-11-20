#include <iostream>

using namespace std;

const int ROWS = 2;
const int COLS = 2;

int main() {
    int A[ROWS][COLS] = {{1, 2},
                             {3, 4}};

    int B[ROWS][COLS] = {{7, 8},
                             {11, 12}};

    int C[ROWS][COLS] = {{0}};

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            for (int k = 0; k < COLS; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Result matrix C:" << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
