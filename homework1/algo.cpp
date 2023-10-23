#include <iostream>
#include <vector>
#include <set>

template <typename T>
void insert_set(std::set<T> *ptrSet, int length)
{

    T input;
    std::cout << "Let's fill the set :" << std::endl;
    for (size_t i = 0; i < length; i++)
    {
        std::cout << "Enter element [" << i << "]: ";
        std::cin >> input;
        ptrSet->insert(input);
    }
}

std::vector<std::string> integrate(std::set<char> letters, std::set<int> numbers)
{

    std::vector<std::string> result;

    auto iterator_letters = letters.begin();
    auto iterator_numbers = numbers.begin();

    while (iterator_letters != letters.end() && iterator_numbers != numbers.end())
    {
        if (static_cast<int>(*iterator_letters) == *iterator_numbers)
        {
            result.push_back(*iterator_letters + std::to_string(*iterator_numbers));
        }
        iterator_letters++;
        iterator_numbers++;
    }

    return result;
}

void print(std::vector<std::string> vector)
{
    for (std::string element : vector)
    {
        std::cout << element << ", ";
    }
}

int main()
{
    size_t length;

    std::cout << "Enter length of set : ";
    std::cin >> length;

    std::set<char> letters;
    insert_set(&letters, length);
    std::set<int> numbers;
    insert_set(&numbers, length);

    std::vector<std::string> result = integrate(letters, numbers);
    print(result);
    return 0;
}