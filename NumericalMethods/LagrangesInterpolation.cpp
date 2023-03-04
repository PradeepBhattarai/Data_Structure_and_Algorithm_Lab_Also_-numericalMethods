#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "no of datas" << endl;
    cin >> n;
    float x[n], y[n], sum = 0, xn, p;
    cout << "x,y pair" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    cout << "To interpolate x= :";
    cin >> xn;
    for (int i = 0; i < n; i++)
    {
        p = 1;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                p = p * (xn - x[j]) / (x[i] - x[j]);
            }
        }
        sum += p * y[i];
    }
    cout << "y(" << xn << ")=" << sum;
    return 0;
}