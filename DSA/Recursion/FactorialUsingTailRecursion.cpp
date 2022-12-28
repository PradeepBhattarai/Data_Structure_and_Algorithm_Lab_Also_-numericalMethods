#include<iostream>
using namespace std;
int tail_fact(int n)
{
    if(n==1)
        return 1;
    else
        return n*tail_fact(n-1);
}
int fact(int n)
{
    return tail_fact(n);
}
int main()
{
    int n;
    cout<<"Enter a number to find factorial: ";
    cin>>n;
    cout<<"The factorial of "<<n<<" is: "<<fact(n);
    return 0;
}