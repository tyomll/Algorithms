#include <iostream>

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void merge(int arr[], int left, int mid, int right)
{

    // create 2 arrays

    int len_1 = mid - left + 1;
    int len_2 = right - mid;

    int arr_left[len_1];
    int arr_right[len_2];

    for (int i = 0; i < len_1; i++)
    {
        arr_left[i] = arr[left + i];
    }

    std::cout << "arr_left : ";
    print_array(arr_left, len_1);

    for (int i = 0; i < len_2; i++)
    {
        arr_right[i] = arr[mid + i + 1];
    }

    std::cout << "arr_right : ";
    print_array(arr_right, len_2);

    // change original array
    int i = 0, j = 0, k = left;

    while (i < len_1 && j < len_2)
    {
        if (arr_left[i] < arr_right[j])
        {
            arr[k] = arr_left[i];
            i++;
        }
        else
        {
            arr[k] = arr_right[j];
            j++;
        }
        k++;
    }

    while (i < len_1)
    {
        arr[k] = arr_left[i];
        i++;
        k++;
    }

    while (j < len_2)
    {
        arr[k] = arr_right[j];
        j++;
        k++;
    }
    print_array(arr, 6);
    std::cout << "\n ------------------------- \n";
}

void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    print_array(arr, size);

    merge_sort(arr, 0, size - 1);

    std::cout << "Sorted array: ";
    print_array(arr, size);

    return 0;
}
