#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cout << "Enter the degree of the polynomial: ";
    cin >> n;
    int num_points;
    cout << "Enter the number of data points: ";
    cin >> num_points;
    double x_values[num_points], y_values[num_points];

    // Input the data points
    cout << "Enter the x and y values separated by a space:\n";
    for (int i = 0; i < num_points; i++)
    {
        double x, y;
        cin >> x >> y;
        x_values[i] = x;
        y_values[i] = y;
    }

    // Compute the coefficients of the polynomial
    int num_coefficients = n + 1;
    double coefficients[num_coefficients];
    double A[num_coefficients][num_coefficients] = {};
    double B[num_coefficients] = {};

    for (int i = 0; i < num_points; i++)
    {
        for (int j = 0; j < num_coefficients; j++)
        {
            for (int k = 0; k < num_coefficients; k++)
            {
                A[j][k] += pow(x_values[i], j + k);
            }
            B[j] += y_values[i] * pow(x_values[i], j);
        }
    }

    // Solve the system of linear equations by gauss elimination method of partial pivoting
    for (int k = 0; k < num_coefficients - 1; k++)
    {
        for (int i = k + 1; i < num_coefficients; i++)
        {
            double factor = A[i][k] / A[k][k];
            for (int j = k; j < num_coefficients; j++)
            {
                A[i][j] -= factor * A[k][j];
            }
            B[i] -= factor * B[k];
        }
    }
    for (int k = num_coefficients - 1; k >= 0; k--)
    {
        for (int j = k + 1; j < num_coefficients; j++)
        {
            B[k] -= A[k][j] * coefficients[j];
        }
        coefficients[k] = B[k] / A[k][k];
    }

    // Output the coefficients of the polynomial
    cout << "The coefficients of the polynomial are:\n";
    for (int i = 0; i < num_coefficients; i++)
    {
        cout << "a[" << i << "] = " << coefficients[i] << endl;
    }

    return 0;
}
