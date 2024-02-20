#include<bits/stdc++.h>
using namespace std;
#define EPSILON 0.0001

double func(double x, vector<double> coefficients)
{
    double result = 0.0;
    int degree = coefficients.size() - 1;
    for (int i = 0; i <= degree; i++)
    {
        result += coefficients[i] * pow(x, degree - i);
    }
    return result;
}

void bisection(double a, double b, vector<double> coefficients)
{
    if (func(a, coefficients) * func(b, coefficients) >= 0)
    {
        cout << "You have not assumed right a and b\n";
        return;
    }

    double c = a;
    int i=0;
    while ((b - a) >= EPSILON)
    {
        i++;
        c = (a + b) / 2;

        if (func(c, coefficients) == 0.0)
            break;

        else if (func(c, coefficients) * func(a, coefficients) < 0)
            b = c;
        else
            a = c;
    }
    cout << "The value of root is : " << c <<"No of iteration: "<<i<<endl;
}

int main()
{
    double a, b;
    int degree;

    cout << "Enter the degree of the polynomial: ";
    cin >> degree;

    vector<double> coefficients(degree + 1);
    cout << "Enter the coefficients of the polynomial (from highest degree to lowest):\n";
    for (int i = degree; i >= 0; i--)
    {
        cout << "Coefficient of x^" << i << ": ";
        cin >> coefficients[i];
    }

    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;

    bisection(a, b, coefficients);
    return 0;
}
