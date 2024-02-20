#include <bits/stdc++.h>
using namespace std;

double fun(double x, double y)
{
    double f = (y-x)/(x+y);
    return f;
}

// 0 1 0.05 0.1

int main()
{
    int n;
    double h;
    double x0,y0,x1,x2,y1,y2,x,y,f0,f1,f2;
    cin >> x0 >> y0 >> h >> x ;

    x1 = x0 + h;
    f0 = fun(x0,y0);
    y1 = y0 + h*f0;

    f1 = fun(x1,y1);

    y1 = y0 + h*(f0+f1)/2;


    cout << "y1 = " << y1 << endl;


    y2 = y0 + 2*h*fun(x1,y1);
    x2 = x1 + h;


    f2 = fun(x2,y2);

    y2 = y1 + h*(f1+f2)/2;


    cout << "y2 = " << y2 << endl;


}
