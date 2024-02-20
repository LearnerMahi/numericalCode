#include <iostream>
#include <cmath>
#include <string>
#include <functional>

using namespace std;

float evaluateEquation(const string& equation, float x, float y) {
    // You would need to implement code here to parse and evaluate the equation string.
    // For simplicity, we'll use a placeholder that handles equations of the form a*x^n + b*y + c.
    // You should replace this with actual parsing and evaluation for any order equation.
    // Example equation: x^3 + y^2 - 3*x*y
    return pow(x, 3) + pow(y, 2) - 3 * x * y;
}

float rk(float x0, float y0, float x1, float x2, float h, const function<float(float, float)>& equation) {
    float y = y0;

    int n = ceil((x2 - x1) / h);
    for (int i = 1; i <= n; i++) {
        float k1, k2, k3, k4;
        k1 = h * equation(x0, y);
        k2 = h * equation(x0 + 0.5 * h, y + 0.5 * k1);
        k3 = h * equation(x0 + 0.5 * h, y + 0.5 * k2);
        k4 = h * equation(x0 + h, y + k3);

        y = y + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        x0 = x0 + h;
    }
    return y;
}

int main() {
    float x0 = 0, y = 1, x1 = 0.1, x2 = 0.2, h = 0.1;

    cout << "Enter the equation in terms of x and y (e.g., x^3 + y^2 - 3*x*y): ";
    string equationStr;
    getline(cin, equationStr);

    // Define a lambda function to evaluate the equation
    auto equation = [equationStr](float x, float y) {
        return evaluateEquation(equationStr, x, y);
    };

    cout << "Value of y at x is : " << rk(x0, y, x1, x2, h, equation);

    return 0;
}
