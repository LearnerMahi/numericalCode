#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

void string_int(string s1, float &a, float &b, float &c)
{
    string s;
    int i=0;

    while (s1[i]!='\0')
    {
        if (s1[i]=='x'&&s1[i+1]=='^'&&s1[i+2]=='2'&&i==0)
        {
            a=1;
            i+=3;
        }
        else if (s1[i]=='x'&&s1[i+1]=='^' && s1[i+2]=='2')
        {
            if (s.length()==1&&(s[0]=='+'||s[0]=='-'))
            {
                s +='1';
            }
            int k = stof(s);
            s.clear();
            a=k;
            i+=3;
        }
        else if (s1[i] == 'x')
        {
            if (s.length() == 1 && (s[0] == '+' || s[0] == '-'))
            {
                s += '1';
            }
            int k = stof(s);
            s.clear();
            b = k;
            i++;
        }
        else if (s1[i + 1] == '\0')
        {
            s += s1[i];
            int k = stof(s);
            s.clear();
            c = k;
            i++;
        }
        else if (s1[i] == '+' || s1[i] == '-' || isdigit(s1[i]))
        {
            s += s1[i];
            i++;
        }
        else
        {
            i++;
        }
    }
}

float evaluate(float a, float b, float c, float x)
{
    return a*x*x+b*x+c;
}

void bisection(float a, float b, float c)
{
    float x1 = -sqrt(pow(b/a,2)-2*(c/a));
    float x2 = -x1, x0;
    while (true)
    {
        x0 = (x1 + x2) / 2;
        float f0 = evaluate(a,b,c,x0);
        float f1 = evaluate(a,b,c,x1);
        float f2 = evaluate(a,b,c,x2);

        if (abs(x0-x1)<=0.0001 && abs(x0 - x2) <= 0.0001)
        {
            break;
        }
        if (f0 * f1 < 0)
        {
            x2 = x0;
        }
        else if (f0 * f2 < 0)
        {
            x1 = x0;
        }
    }
    cout << "Bisection result : " << x0 << endl;
    float fx0=evaluate(a,b,c,x0);
    cout<<fx0<<endl;


}

int main()
{
    string s="x^2-4x-10";
    float a = 0, b = 0, c = 0;


    string_int(s, a, b, c);


    bisection(a, b, c);
}
