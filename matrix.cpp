#include <iostream>
#include <vector>

std::vector<std::vector<int>> matrix_multiply(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2) {
    int rows1 = mat1.size();
    int cols1 = mat1[0].size();
    int rows2 = mat2.size();
    int cols2 = mat2[0].size();

    if (cols1 != rows2) {
        std::cout << "Matrix multiplication not possible!";
        return {};
    }

    std::vector<std::vector<int>> result(rows1, std::vector<int>(cols2, 0));

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return result;
}

void display_matrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> matrix1 = {{2, 7, 3}, {4, 1, 6}};
    std::vector<std::vector<int>> matrix2 = {{7, 6}, {1, 2}, {3, 5}};

    std::cout << "Matrix 1:" << std::endl;
    display_matrix(matrix1);

    std::cout << "Matrix 2:" << std::endl;
    display_matrix(matrix2);

    std::vector<std::vector<int>> result = matrix_multiply(matrix1, matrix2);

    if (!result.empty()) {
        std::cout << "Resultant Matrix:" << std::endl;
        display_matrix(result);
    }

    return 0;
}

