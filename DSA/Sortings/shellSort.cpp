#include <iostream>
using namespace std;

void shellSort(int arr[], int n)
{
    int flag = 1, gapSize = n;
    while(flag==1 || gapSize>1)
    {
        flag = 0;
        gapSize = (gapSize + 1) / 2;
        for (int i = 0; i < (n - gapSize);i++)
        {
            if(arr[i+gapSize]<arr[i])//ascending
            {
                int temp = arr[i];
                arr[i] = arr[gapSize + i];
                arr[gapSize + i] = temp;
                flag = 0;
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
    shellSort(arr, n);
    cout << "The Sorted Array is:";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }

    return 0;
}