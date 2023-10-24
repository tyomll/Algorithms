#include <iostream>
#include <vector>

int reverseNumber(int number)
{
    int reversed = 0;
    while (number > 0)
    {
        reversed = reversed * 10 + number % 10;
        number /= 10;
    }
    return reversed;
}

bool isPalindrome(int number)
{
    return (number) && (number == reverseNumber(number));
}

int main()
{
    std::vector<int> numbers = {121, 12321, 123, 1331, 45654, 78987};

    std::cout << "Palindromic numbers in the array: ";
    for (int number : numbers)
    {
        if (isPalindrome(number))
        {
            std::cout << number << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}
