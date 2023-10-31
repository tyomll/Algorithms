#include <iostream>
#include <vector>

void getIndex(std::vector<int> &array, std::vector<int> &arrayOfIndex, int target)
{

    for (int i = 0; i < array.size() - 1; i++)
    {
        for (int j = i + 1; j < array.size(); j++)
        {

            if (array[i] + array[j] == target)
            {
                arrayOfIndex.push_back(i);
                arrayOfIndex.push_back(j);
                return;
            }
        }
    }
}
void printArray(std::vector<int> &array)
{
    for (int i = 0; i < 2; i++)
    {

        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
int main()
{
    std::vector<int> array;
    std::vector<int> arrayOfIndex;
    array.push_back(5);
    array.push_back(4);
    array.push_back(2);
    array.push_back(9);
    array.push_back(10);
    array.push_back(18);
    array.push_back(6);
    array.push_back(1);

    getIndex(array, arrayOfIndex, 6);
    printArray(arrayOfIndex);
}