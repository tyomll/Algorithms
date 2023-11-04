#include <iostream>
#include <list>

void megre_lists(std::list<int> list1, std::list<int> list2, std::list<int> merged_list)
{
    std::list<int>::iterator it1 = list1.begin();
    std::list<int>::iterator it2 = list1.begin();

    while (it1 != list1.end() && it2 != list1.end())
    {
        if (*it1 <= *it2)
        {
            merged_list.push_back(*it1);
            it1++;
        }
        else
        {
            merged_list.push_back(*it2);
            it2++;
        }
    }
}

int main()
{
    std::list<int> list1 = {1, 2, 4};
    std::list<int> list2 = {1, 3, 4};
    std::list<int> merged_list;

    list1.merge(list2);

    std::cout << "Merged List: ";
    for (const int &element : list1)
    {
        std::cout << element << "  ";
    }

    return 0;
}
