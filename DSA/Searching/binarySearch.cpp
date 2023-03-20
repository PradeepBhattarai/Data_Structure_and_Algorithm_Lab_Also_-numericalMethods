#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {0, 2, 3, 4, 9, 10, 32, 36, 45, 87};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 90;

    int result = binarySearch(arr, n, key);

    if (result == -1)
    {
        cout << "Element not found." << endl;
    }
    else
    {
        cout << "Element found at index: " << result << endl;
    }

    return 0;
}
