#include <iostream>
#include <cmath>
using namespace std;
float f(float x)
{
    return 1 + cos(x) * cos(x);
}
int main()
{
    float a, b, h;
    int n;
    cout << "Enter the lower and upper limits:";
    cin >> a >> b;
    cout << "Enter the number of divs:";
    cin >> n;
    h = (b - a) / n;
    cout << "x\ty" << endl;
    float y[n + 1], x[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        x[i] = a + i * h;
        y[i] = f(x[i]);
    }
    float sum = 0;
    cout << x[0] << "\t" << y[0] << endl;
    for (int i = 1; i < n; i++)
    {
        if (i % 3 == 0)
            sum += 2 * y[i];
        else
            sum += 3 * y[i];
        cout << x[i] << "\t" << y[i] << endl;
    }
    sum = sum + y[0] + y[n];
    float ans = 3 * h / 8 * sum;
    cout << "The solution is :";
    cout << ans << endl;
    return 0;
}