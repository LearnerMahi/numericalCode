#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double parseEquation(const string& equation, double x, double y) {
    string parsedEquation = equation;
    size_t found = parsedEquation.find("^");
    while (found != string::npos) {
        // Replace '^' with '**' to represent exponentiation for the parser.
        parsedEquation.replace(found, 1, "**");
        found = parsedEquation.find("^", found + 2);
    }

    // Replace 'x' and 'y' placeholders with their values.
    size_t xPos = parsedEquation.find("x");
    while (xPos != string::npos) {
        parsedEquation.replace(xPos, 1, to_string(x));
        xPos = parsedEquation.find("x", xPos + 1);
    }

    size_t yPos = parsedEquation.find("y");
    while (yPos != string::npos) {
        parsedEquation.replace(yPos, 1, to_string(y));
        yPos = parsedEquation.find("y", yPos + 1);
    }

    // Evaluate the parsed expression.
    double result = 0.0;
    try {
        result = stod(parsedEquation);
    } catch (const exception& e) {
        cerr << "Error parsing equation: " << e.what() << endl;
    }

    return result;
}

double dydx(double x, double y, const string& equation) {
    return parseEquation(equation, x, y);
}

double rk(double x0, double y0, double x, double h, const string& equation) {
    double y = y0;

    int n = static_cast<int>((x - x0) / h);
    for (int i = 1; i <= n; i++) {
        double k1, k2, k3, k4;
        k1 = h * dydx(x0, y, equation);
        k2 = h * dydx(x0 + 0.5 * h, y + 0.5 * k1, equation);
        k3 = h * dydx(x0 + 0.5 * h, y + 0.5 * k2, equation);
        k4 = h * dydx(x0 + h, y + k3, equation);

        y = y + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        x0 = x0 + h;
    }

    return y;
}

int main() {
    double x0 = 0.0, y = 1.0, x = 0.2, h = 0.1;

    // Get the equation from the user as a string.
    string equation;
    cout << "Enter the equation (e.g., 'x + y^2'): ";
    getline(cin, equation);

    double result = rk(x0, y, x, h, equation);

    cout << "The value of y at x is: " << result << endl;

    return 0;
}
