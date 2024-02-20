// Integrate y= log(x) in range of 4 to 5.2 in Trapezoidal Method

//Equation:  (h/2)* [(Y0 + Yn-1) + 2(Y1 + Y2 + Y3+ Y4 + Y5 + Y6 + Y7 + Y8 + ...+ Yn-2) ]

#include<bits/stdc++.h>
using namespace std;

float a, b, h, n;       // a-> Lower bound,  b-> Upper bound,  h-> Interval,  n-> Number of steps

float y(float x){
    float z= log(x);   // put the function here and the rest will be the same.
    return z;
}

float Trapezoidal(){

    float sum = y(a)+y(b);                          //Y0 + Y6

    for (int i = 1; i < n-1; i++)
        sum += (2*y(a+i*h));                        //2(Y1 + Y2 + Y3+ Y4 + Y5 )

    return (h/2)*sum;
}

int main(){

    ifstream inp("input.txt");
    inp>>a>>b;
    h= 0.1;
    n = ((b-a)*10)+1;

    printf("Value of integral is:  %0.8f\n", Trapezoidal());
    return 0;
}
