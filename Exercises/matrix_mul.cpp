#include <iostream>
#include <vector>

std::vector<std::vector<int>> multiplyMatrices(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int rows2 = matrix2.size();
    int cols2 = matrix2[0].size();  
      for (int i = 1; i < rows1; ++i) {
        if (matrix1[i].size() != cols1) {
            std::cout << "Can not multipy this vectors\n";
            return {};
        }
    }

    for (int i = 1; i < rows2; ++i) {
        if (matrix2[i].size() != cols2) {
            std::cout << "Can not multipy this vectors\n";
            return {};
        }
    }

    if (cols1 != rows2) {
        std::cout << "Cannot multiply matrices: Invalid dimensions";
        return {};
    }

    std::vector<std::vector<int>> result(rows1, std::vector<int>(cols2, 0));

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

void displayMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> matrix1 = {{1, 2, 3},
                                             {4, 5, 6}};
    std::vector<std::vector<int>> matrix2 = {{7, 8},
                                             {9, 10},
                                             {11, 12}};

    std::cout << "Matrix 1:" << std::endl;
    displayMatrix(matrix1);

    std::cout << "Matrix 2:" << std::endl;
    displayMatrix(matrix2);

    std::vector<std::vector<int>> result = multiplyMatrices(matrix1, matrix2);

    std::cout << "Result:" << std::endl;
    displayMatrix(result);

    return 0;
}
