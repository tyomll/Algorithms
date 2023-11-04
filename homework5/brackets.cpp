#include <iostream>

bool check(std::string text)
{
    while (!text.empty())
    {
        bool found = false;
        for (int i = 0; i < text.length() - 1; i++)
        {
            if ((text[i] == '(' && text[i + 1] == ')') ||
                (text[i] == '{' && text[i + 1] == '}') ||
                (text[i] == '[' && text[i + 1] == ']'))
            {
                text.erase(i, 2);
                found = true;
                break;
            }
        }
        if (!found)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::string text;
    std::cout << "Enter the text: ";
    std::cin >> text;

    if (check(text))
    {
        std::cout << "OK" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
