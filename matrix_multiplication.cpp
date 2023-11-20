#include <iostream>
#include <vector>

void input(int &row1, int &row2, int &column1, int &column2, std::vector<std::vector<int>> &matrix1, std::vector<std::vector<int>> &matrix2) {
    std::cout << "Enter the row of first matrix: ";
    std::cin >> row1;
    std::cout << "Enter the column of first matrix: ";
    std::cin >> column1;
    std::cout << "Enter the row of second matrix: ";
    std::cin >> row2;
    std::cout << "Enter the column of second matrix: ";
    std::cin >> column2;

    matrix1.resize(row1, std::vector<int>(column1));
    matrix2.resize(row2, std::vector<int>(column2));

    if (row1 != column2) {
        std::cout << "Row of first matrix not equal to column of second! Try again!" << "\n";
        return;
    }

    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < column1; ++j) {
            std::cout << "Enter the a" << i + 1 << "." << j + 1 << " element of first matrix: ";
            std::cin >> matrix1[i][j];
        }
    }

    std::cout << "Thanks!" << "\n";

    for (int i = 0; i < row2; ++i) {
        for (int j = 0; j < column2; ++j) {
            std::cout << "Enter the b" << i + 1 << "." << j + 1 << " element of second matrix: ";
            std::cin >> matrix2[i][j];
        }
    }
}

void multiplication(int row1, int column1, int row2, int column2, const std::vector<std::vector<int>> &matrix1, const std::vector<std::vector<int>> &matrix2, std::vector<std::vector<int>> &matrix3) {
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < column2; ++j) {
            matrix3[i][j] = 0;
            for (int k = 0; k < column1; ++k) {
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void print(int row1, int column2, const std::vector<std::vector<int>> &matrix3) {
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < column2; ++j) {
            std::cout << matrix3[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    int row1, row2;
    int column1, column2;

    std::vector<std::vector<int>> matrix1;
    std::vector<std::vector<int>> matrix2;
    std::vector<std::vector<int>> matrix3;

    input(row1, row2, column1, column2, matrix1, matrix2);

    matrix3.resize(row1, std::vector<int>(column2, 0));

    multiplication(row1, column1, row2, column2, matrix1, matrix2, matrix3);
    print(row1, column2, matrix3);

    return 0;
}