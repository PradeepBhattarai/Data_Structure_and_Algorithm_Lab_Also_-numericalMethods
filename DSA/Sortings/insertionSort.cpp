#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int j = 1; j < n; j++)
    {
        int temp = arr[j];
        int i = j - 1;
        while(i>=0 && temp<=arr[i])
        {
            arr[i + 1] = arr[i];//swap
            i--;
        }
        arr[i + 1] = temp;
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
    insertionSort(arr, n);
    cout << "The Sorted Array is:";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }

    return 0;
}