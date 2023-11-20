#include <iostream>
#include <vector>

void coutVector(const std::vector<std::vector<int>>& vec) {
    for (const auto& row : vec) {
        std::cout << "|";
        for (const auto& element : row) {
            std::cout << " " << element << " ";
        }
        std::cout << "|" << std::endl;
    }
}

std::vector<std::vector<int>> multiplicateVectors(const std::vector<std::vector<int>>& firstVec, const std::vector<std::vector<int>>& secondVec) {
    int firstVecColumn = firstVec.size();
    int firstVecRow = firstVec[0].size();

    for (int i = 1; i < firstVecColumn; ++i) {
        if (firstVec[i].size() != firstVecRow) {
            std::cout << "Cannot multiply these vectors\n";
            return {{}};
        }
    }

    int secondVecColumn = secondVec.size();
    int secondVecRow = secondVec[0].size(); 

    for (int i = 1; i < secondVecColumn; ++i) {
        if (secondVec[i].size() != secondVecRow) {
            std::cout << "Cannot multiply these vectors\n";
            return {{}};
        }
    }

    if (firstVecRow != secondVecColumn) {
        std::cout << "Cannot multiply these vectors\n";
        return {{}};
    }

    std::vector<std::vector<int>> result(firstVecColumn, std::vector<int>(secondVecRow, 0));

    for (int i = 0; i < firstVecColumn; i++) {
        for (int j = 0; j < secondVecRow; j++) {
            for (int k = 0; k < firstVecRow; k++) {
                result[i][j] += firstVec[i][k] * secondVec[k][j];
            }
        }
    }

    return result;
}

int main() {
    std::vector<std::vector<int>> firstVec = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<int>> secondVec = {{7, 8, 9}, {11, 9, 10}, {0, 2, 3}};
    std::vector<std::vector<int>> result = multiplicateVectors(firstVec, secondVec);

    coutVector(result);

    return 0;
}
