#include<iostream>
using namespace std;
int tail_fibonacii(int n)
{
    if(n==0||n==1)
        return n;
    else
        return tail_fibonacii(n-1)+tail_fibonacii(n-2);
}
int fibonacii(int n)
{
    return tail_fibonacii(n);
}
int main()
{
    int n;
    cout<<"Enter the no of terms to display:";
    cin>>n;
    cout<<"Fibonacii Upto "<<n<<" terms is: "<<fibonacii(n);
    return 0;
}