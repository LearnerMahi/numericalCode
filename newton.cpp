//newton raphson method
#include<bits/stdc++.h>
using namespace std;


//function f(x) = 3x-cos(x)-1

double f(double x)
{

//    double a=3.0*x-1;
//
//    double b=x*3.14/180.0;
//
//    double c=cos(b);

    //return a-c;

    return 3*x-cos(x)-1;
}

double f_derivative(double x)
{

     //double b=x*3.14/180.0;

     //double c=sin(b);
     return 3+sin(x);
}

int main()
{
    double x,x1;
    int step=0;

    cout<<"Enter Initial value: ";
    cin>>x;
    double err;
    cout<<"Enter Error Margin: ";
    cin>>err;

    while(1)
    {
         x1 = x - (f(x))/f_derivative(x);

         if(abs(((x1-x)/x1))<=err)break;
         step++;
         x=x1;

    }



    cout<<"Result is :"<<x1<<endl;


    return 0;
}