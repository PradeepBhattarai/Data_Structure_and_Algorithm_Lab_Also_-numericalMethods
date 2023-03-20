#include <iostream>
#include <cmath>
using namespace std;
int getLarge(int arr[],int n)
{
    int large = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > large)
        {
            large = arr[i];
        }
    }
    return large;
}
void radixSort(int arr[], int n)
{
    int large =getLarge(arr,n);
    

    int nop = 0;
    while (large != 0)
    {
        nop++;
        large /= 10;
    }

    int pass = 0;
    while (pass <= nop - 1)
    {
        int i = 0;
        int buckets[10] = {0};
        while (i < n)
        {
            int digit = (arr[i] / static_cast<int>(pow(10, pass))) % 10;
            buckets[digit]++;
            i++;
        }

        i = 1;
        while (i < n)
        {
            buckets[i] += buckets[i - 1];
            i++;
        }

        int temp[n];
        i = n - 1;
        while (i >= 0)
        {
            int digit = (arr[i] / static_cast<int>(pow(10, pass))) % 10;
            temp[buckets[digit] - 1] = arr[i];
            buckets[digit]--;
            i--;
        }

        i = 0;
        while (i < n)
        {
            arr[i] = temp[i];
            i++;
        }

        pass++;
    }
}

int main()
{
    int arr[] = {9, 3, 10, 32, 4, 0, 2, 87, 36, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The unsorted Array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;

    radixSort(arr, n);

    cout << "The Sorted Array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }

    return 0;
}
