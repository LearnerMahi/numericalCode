#include <iostream>
#include <string>
#include <cmath>
int xn;
using namespace std;

// Function to evaluate the equation
float evaluateEquation(const string& equation, float x, float y) {
    // You would need to implement code here to parse and evaluate the equation string.
    // For simplicity, we'll just use a simple equation.
    // You can replace this with a more sophisticated parser and evaluator.
    if (equation == "2*x + y") {
        return 2 * x + y;
    } else {
        // Handle other equations here.
        // You should implement proper parsing and evaluation logic.
        return 0.0;
    }
}

int main() {
    float x0, y0, h, yn;
    int n;

    cout << "Enter Initial Condition" << endl;
    cout << "x0 = ";
    cin >> x0;
    cout << "y0 = ";
    cin >> y0;
    cout << "Enter number of steps: ";
    cin >> n;

    // Define the equation as a string
    string equationStr;
    cout << "Enter the equation in terms of x and y (e.g., 2*x + y): ";
    cin.ignore();
    getline(cin, equationStr);

    // Calculate the step size
    cout << "Enter calculation point xn = ";
    cin >> xn;
    h = (xn - x0) / n;

    for (int i = 0; i < n; i++) {
        float slope = evaluateEquation(equationStr, x0, y0);
        yn = y0 + h * slope;
        cout << x0 << "\t" << y0 << "\t" << slope << "\t" << yn << endl;
        y0 = yn;
        x0 = x0 + h;
    }

    cout << "\nValue of y at x = " << xn << " is " << yn;

    return 0;
}
