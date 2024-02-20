#include<bits/stdc++.h>
using namespace std;
float dydx(float x, float y)
{
    return x+y;
}
float rk(float x0, float y0, float x, float h)
{
    float y = y0;

    int n = (int)((x - x0) / h);
    for (int i=1; i<=n; i++)
    {
        float k1, k2, k3, k4, k5;
        k1 = h*dydx(x0, y);
        k2 = h*dydx(x0 + 0.5*h, y + 0.5*k1);
        k3 = h*dydx(x0 + 0.5*h, y + 0.5*k2);
        k4 = h*dydx(x0 + h, y + k3);

        y = y + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);;
        x0 = x0 + h;
    }

    return y;
}



int main()
{
//    int ch;cin >> ch;
//	if(ch){
    float x0=0, y = 1, x = 0.2, h = 0.1;
    cout << "The value of y at x is : " << rk(x0, y, x, h);
//	}else{
//
//	}


    return 0;
}
