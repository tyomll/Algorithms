#include <iostream>

int** multiplyMatrices(int** matrix1, int** matrix2, int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        std::cerr << "Matrices cannot be multiplied. Invalid dimensions." << std::endl;
        return nullptr;
    }

    int** result = new int*[rows1];
    for (int i = 0; i < rows1; i++) {
        result[i] = new int[cols2];
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
        }
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n, m;

    std::cout << "Input size of the first matrix (NxN): ";
    std::cin >> n;

    std::cout << "Input size of the second matrix (MxM): ";
    std::cin >> m;

    int** matrix1 = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix1[i] = new int[n];
    }

    int** matrix2 = new int*[m];
    for (int i = 0; i < m; i++) {
        matrix2[i] = new int[m];
    }

    std::cout << "Input elements of the first matrix:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matrix1[i][j];
        }
    }

    std::cout << "Input elements of the second matrix:" << std::endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> matrix2[i][j];
        }
    }

    std::cout << "First matrix:" << std::endl;
    printMatrix(matrix1, n, n);

    std::cout << "Second matrix:" << std::endl;
    printMatrix(matrix2, m, m);

    int** result = multiplyMatrices(matrix1, matrix2, n, n, m, m);

    if (result != nullptr) {
        std::cout << "Result of Matrix Multiplication:" << std::endl;
        printMatrix(result, n, m);
        delete[] result;
    }
    delete[] matrix1;
    delete[] matrix2;

    return 0;
}

