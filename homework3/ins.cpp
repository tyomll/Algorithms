#include <iostream>
int main()
{
    int arr[4] = {7, 9, 1, 17};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] < arr[j])
            {
                arr[i] = arr[i] + arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j];
            }
        }
        for (int i = 0; i < 4; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}