
#include <iostream>
using namespace std;
 
int factTR(int n, int a)
{
    if (n <= 1)
        return a;
 
    return factTR(n - 1, n * a);
}
 
int fact(int n) { return factTR(n, 1); }
int main()
{
    cout << fact(5);
    return 0;
}