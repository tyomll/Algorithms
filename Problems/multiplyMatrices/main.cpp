#include <iostream>
#include <vector>

using MatrixType = std::vector<std::vector<int>>;

MatrixType multiplyMatrices(const MatrixType& firstMatrix,
                            const MatrixType& secondMatrix) {
    MatrixType multiplied;

    for (size_t i = 0; i < firstMatrix.size(); i++) {
        std::vector<int> newRow;

        for (size_t j = 0; j < secondMatrix[0].size(); j++) {
            int resultElement = 0;

            for (size_t k = 0; k < secondMatrix.size(); k++) {
                resultElement += firstMatrix[i][k] * secondMatrix[k][j];
            }
            newRow.push_back(resultElement);
        }
        multiplied.push_back(newRow);
    }

    return multiplied;
}

std::pair<MatrixType, MatrixType> inputMatrices() {
    int firstRow, firstCol;
    int secondRow, secondCol;
    MatrixType firstMatrix;
    MatrixType secondMatrix;

    std::cout << "Enter First matrix rows count: ";
    std::cin >> firstRow;
    std::cout << "Enter First matrix columns count: ";
    std::cin >> firstCol;
    std::cout << "Enter Second matrix rows count: ";
    std::cin >> secondRow;
    std::cout << "Enter Second matrix columns count: ";
    std::cin >> secondCol;

    for (size_t i = 0; i < firstRow; i++) {
        std::vector<int> newRow;

        for (size_t j = 0; j < firstCol; j++) {
            int input;
            std::cout << "Enter First matrix [" << i << ", " << j << "] - ";
            std::cin >> input;
            newRow.push_back(input);
        }
        firstMatrix.push_back(newRow);
    }

    for (size_t i = 0; i < secondRow; i++) {
        std::vector<int> newRow;

        for (size_t j = 0; j < secondCol; j++) {
            int input;
            std::cout << "Enter Second matrix [" << i << ", " << j << "] - ";
            std::cin >> input;
            newRow.push_back(input);
        }
        secondMatrix.push_back(newRow);
    }
    return std::make_pair(firstMatrix, secondMatrix);
};

void printMatrix(const MatrixType& matrix) {
    for (size_t i = 0; i < matrix.size(); i++) {
        std::cout << "[ ";
        for (size_t j = 0; j < matrix[i].size(); j++) {
            std::cout << matrix[i][j]
                      << (matrix[i].size() - 1 == j ? " " : ", ");
        }
        std::cout << "]" << std::endl;
    }
}

int main() {
    std::pair<MatrixType, MatrixType> matrices = inputMatrices();

    printMatrix(multiplyMatrices(matrices.first, matrices.second));
    return 0;
}