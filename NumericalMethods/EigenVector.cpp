#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout << "Enter the order of matrix: ";
    cin >> n;
    float a[n][n], x[n], z[n];
    cout << "Enter the matrix:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Row" << i + 1 << ":";
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "\nEnter the initial eigen vector:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    float max_diff, eigen_value;
    do
    {
        // Multiplying
        for (int i = 0; i < n; i++)
        {
            float sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += a[i][j] * x[j];
            }
            z[i] = sum;
        }
        // dividing by max value
        float max_value = z[0];
        for (int i = 0; i < n; i++)
        {
            if (max_value < z[i])
            {
                max_value = z[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            z[i] = z[i] / max_value;
        }
        eigen_value = max_value;
        // comparing
        max_diff = fabs(z[0] - x[0]);
        for (int i = 1; i < n; i++)
        {
            if (max_diff < fabs(z[i] - x[i]))
            {
                max_diff = fabs(z[i] - x[i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            x[i] = z[i];
        }
    } while (max_diff >= 0.00005);
    // Printing Ans
    cout << "\nEigen vector:\n";
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << endl;
    }
    cout << "\nEigen value: " << eigen_value;
    return 0;
}
