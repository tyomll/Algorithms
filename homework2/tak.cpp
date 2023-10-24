#include <iostream>
#include <list>

std::list<int> adding(const std::list<int> &arr1, const std::list<int> &arr2)
{
    std::list<int> result;
    auto it1 = arr1.begin();
    auto it2 = arr2.begin();
    int x = 0;

    while (it1 != arr1.end() || it2 != arr2.end() || x != 0)
    {
        int sum = x;
        if (it1 != arr1.end())
        {
            sum += *it1;
            ++it1;
        }
        if (it2 != arr2.end())
        {
            sum += *it2;
            ++it2;
        }

        x = sum / 10;
        result.push_front(sum % 10);
    }

    return result;
}

void print(std::list<int> &arr)
{
    auto first = arr.begin();
    while (first != arr.end())
    {
        std::cout << *first << " ";
        first++;
    }
    std::cout << std::endl;
}

int main()
{
    std::list<int> num1, num2, add;
    num1.push_back(6);
    num1.push_back(5);
    num1.push_back(1);
    num2.push_back(3);
    num2.push_back(7);
    num2.push_back(9);
    num2.push_back(9);
    add = adding(num1, num2);
    print(add);
    std::cout << "Answer: " << 156 + 9973 << std::endl;
    return 0;
}