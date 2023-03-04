#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of datas:" << endl;
    cin >> n;
    float x[n], y[n], sumX = 0.0, sumY = 0.0, sumXY = 0.0, sumX2 = 0.0, a, b;
    cout << "Enter the values of x and y:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        y[i] = log(y[i]);
    }
    for (int i = 0; i < n; i++)
    {
        // cout << x[i]<<"\t"<< y[i]<<endl;
        sumX = sumX + x[i];
        sumY = sumY + y[i];
        sumXY = sumXY + x[i] * y[i];
        sumX2 = sumX2 + x[i] * x[i];
    }

    b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    a = exp((sumY - b * sumX) / n);
    cout << "The value of a =" << a << endl;
    cout << "The value of b =" << b << endl;
    cout << "The req. equ is: y= " << a << "e^" << b << "x";

    return 0;
}