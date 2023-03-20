#include <iostream>
using namespace std;
int search(int arr[],int key,int n)
{
    
    int flag = 0;
    for (int i = 0; i < n;i++)
    {
        if(key==arr[i])
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    int arr[] = {9, 3, 10, 32, 4, 10, 2, 87, 36, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
   
    if (search(arr,key,n))
    {
        cout << "Found" << endl;
        cout << "Occurring index=:" <<search(arr,key,n);
    }
    else{
        cout << "Not found";
    }

    return 0;
}
