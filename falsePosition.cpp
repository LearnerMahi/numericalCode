#include<iostream>
#include<iomanip>
#include<cmath> // Use cmath for math functions

using namespace std;

// Define the function f(x)
double f(double x) {
    return cos(x) - x * exp(x);
}

int main() {
    double x0, x1, x, f0, f1, fx, e;
    int step = 1;

    cout << "Enter first guess: ";
    cin >> x0;
    cout << "Enter second guess: ";
    cin >> x1;
    cout << "Enter tolerable error: ";
    cin >> e;

    do {
        f0 = f(x0);
        f1 = f(x1);
        x = (x0 * f1 - x1 * f0) / (f1 - f0);
        fx = f(x);

        if (f0 * fx < 0) {
            x1 = x;
        } else {
            x0 = x;
        }
        step = step + 1;
    } while (fx>= e); // Compare the absolute value of f(x) with e

    cout << endl << "Root is: " << x << endl;

    return 0;
}
