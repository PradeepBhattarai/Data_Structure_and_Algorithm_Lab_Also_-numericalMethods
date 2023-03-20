#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n-j-1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
int main()
{
    int arr[] = {9, 3, 10, 32, 4, 0, 2, 87, 36, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The unsorted Array is:";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
    bubbleSort(arr, n);
    cout << "The Sorted Array is:";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }

    return 0;
}