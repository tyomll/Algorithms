#include <iostream>
#include <list>

std::list<int> rotate(std::list<int> &list, int k)
{
    while (k > 0)
    {
        int tmp = list.back();
        list.pop_back();
        list.push_front(tmp);
        k--;
    }
    return list;
}

void print(std::list<int> &list)
{
    for (int element : list)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::list<int> list1 = {1, 2, 3, 4, 5};
    list1 = rotate(list1, 2);
    print(list1);
    return 0;
}