#include <iostream>
#include <vector>

int binSearch(std::vector<int> &list, int target)
{
    int begin = 0;
    int end = list.size();
    int index = end / 2;

    while (begin != end)
    {
        if (list[index] == target)
        {
            return index;
        }
        else if (list[index] < target)
        {
            begin = index + 1;
        }
        else if (list[index] > target)
        {
            end = index - 1;
        }
        index = (begin + end) / 2;
    }
    return -1;
}

int main()
{
    std::vector<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(5);
    list.push_back(8);
    list.push_back(11);
    list.push_back(15);
    list.push_back(17);
    list.push_back(18);
    list.push_back(20);
    list.push_back(25);
    list.push_back(78);

    std::cout << binSearch(list, 785);
}
