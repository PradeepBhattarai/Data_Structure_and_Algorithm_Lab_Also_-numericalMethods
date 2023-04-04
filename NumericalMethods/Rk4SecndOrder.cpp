#include <iostream>
#include <cmath>
using namespace std;

float f(float x, float y, float z)
{
    return z;
}
float g(float x, float y, float z)
{
    return x*y*y-y*y;
}
int main()
{
    float x0, y, z, xn, h, l, k, k1, k2, k3, k4, l1, l2, l3, l4;
    cin >> x0 >> y >> z >> xn >> h;
    cout << "x\t"
         << "y\t"
         << "z\n";
    do
    {
        k1 = h * f(x0, y, z);
        l1 = h * g(x0, y, z);
        k2 = h * f(x0 + h / 2, y + k1 / 2, z + l1 / 2);
        l2 = h * g(x0 + h / 2, y + k1 / 2, z + l1 / 2);
        k3 = h * f(x0 + h / 2, y + k2 / 2, z + l2 / 2);
        l3 = h * g(x0 + h / 2, y + k2 / 2, z + l2 / 2);
        k4 = h * f(x0 + h, y + k3, z + l3);
        l4 = h * g(x0 + h, y + k3, z + l3);
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        l = (l1 + 2 * l2 + 2 * l3 + l4) / 6;
        cout << x0 << "\t" << y << "\t" << z << "\n";
        y = y + k;
        z = z + l;
        x0 = x0 + h;
    } while (x0 < xn);
    cout << "x=" << x0 << endl;
    cout << "y=" << y << endl;
    cout << "z=" << z << endl;

    return 0;
}
