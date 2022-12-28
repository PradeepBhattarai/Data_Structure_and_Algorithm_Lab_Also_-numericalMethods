#include<iostream>
using namespace std;
long int factorial(long int n)
{
    if(n==1)
        return 1;
    else
        return n*factorial(n-1);
}
int main()
{
    cout<<"Enter the Number to find factorial.\n";
    long int n;
    cin>>n;
    cout<<"The factorial of "<<n<<" is: "<<factorial(n);
    return 0;
}