#include<iostream>
using namespace std;
int fibonacii(int n)
{
    if(n==0||n==1)
        return n;
    else
        return fibonacii(n-1)+fibonacii(n-2);
}
int main()
{
    int n;
    cout<<"Enter the no of terms to display:";
    cin>>n;
    cout<<"Fibonacii Upto "<<n<<" terms is: "<<fibonacii(n);
    return 0;
}