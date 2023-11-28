#include <iostream>
#include <vector>

std::vector<std::vector<int>> inputMatrix()
{

    int column, row, value;
    std::cout << "input quantity of rows: ";
    std::cin >> row;

    std::cout << "input quantity of columns: ";
    std::cin >> column;

    std::cout << "\n";

    std::vector<std::vector<int>> matrix(row, std::vector<int>(column)); // Initialize the matrix with correct dimensions

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            std::cout << "enter matrix[" << i << "]"
                      << "[" << j << "] = ";
            std::cin >> matrix[i][j];
        }
    }
    std::cout << "\n";
    return matrix;
}

void print(std::vector<std::vector<int>> matrix)

{
    std::cout << "["
              << "\n";
    for (int i = 0; i < matrix.size(); i++)
    {
        std::cout << " [ ";

        for (int j = 0; j < matrix[0].size(); j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "]"
                  << "\n";
    }
    std::cout << "]"
              << "\n \n";
}

std::vector<std::vector<int>> multiply(std::vector<std::vector<int>> matrix1, std::vector<std::vector<int>> matrix2)
{
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int cols2 = matrix2[0].size();

    std::vector<std::vector<int>> result(rows1, std::vector<int>(cols2, 0));

    for (int i = 0; i < rows1; ++i)
    {
        for (int j = 0; j < cols2; ++j)
        {
            for (int k = 0; k < cols1; ++k)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

int main()
{
    std::vector<std::vector<int>> matrix1 = inputMatrix();
    std::vector<std::vector<int>> matrix2 = inputMatrix();

    std::vector<std::vector<int>> result = multiply(matrix1, matrix2);

    print(result);
    return 0;
}