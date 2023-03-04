
#include <iostream>
#include <cmath>
using namespace std;

float f(float x, float y, float z)
{
    return z;
}
float g(float x, float y, float z)
{
    return -(6*x+z*z)/10;
}
int main()
{
    float x0, y, z, xn, h, l, k, k1, k2, l1, l2;
    cin >> x0 >> y >> z >> xn >> h;
    cout << "x\t"
         << "y\t"
         << "z\n";
    do
    {
        k1 = h * f(x0, y, z);
        l1 = h * g(x0, y, z);
        k2 = h * f(x0 + h , y + k1 , z + l1 );
        l2 = h * g(x0 + h , y + k1 , z + l1 );
        k = (k1 +k2) /2;
        l = (l1 +l2) /2;
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