#include<bits/stdc++.h>
using namespace std;
float f(float x,float y)
{
    return x+y;
}
int main()
{
    float x,y,x1,x2,h;
    int n;
    x=0;
    y=1;
    x1=0.1;
    x2=0.2;
    h=0.1;

    n = ceil((x2-x1)/h);

    float k1,k2,k3,k4;
    for(int i=0; i<2; i++)
    {
        k1=h*f(x,y);
        k2=h*f(x+(h/2), y+(k1/2));
        k3=h*f(x+(h/2), y+k2/2);
        k4 = h*f(x+h, y+k3);

        x+=h;
        y+=(1.0/6.0)*(k1+2*k2+2*k3+k4);
    }

    cout<<"Value of y is : "<<y<<endl;
}