#include<bits/stdc++.h>
using namespace std;

void sin(){
    cout << " You entered sin function"<<endl;
    float l;
    cout << "Input lower limit: ";
    cin >> l;

    float u;
    cout << "Input Upper limit: ";
    cin >> u;

    float n;
    cout << "Input n: ";
    cin >>n;
    u = u*3.1416/180;
    l = l*3.1416/180;
    float h = (u-l)/n;

    float sum = 0.5*(sin(u)+sin(l));
    for(int i=1;i<n;i++)
    {
        sum = sum + sin(l+i*h);
    }
    sum*=h;
    cout << "\nActual result: " << sum;
    float res = (-cos(u))-(-cos(l));
    cout << "\nTheoritical resut: "<< res;
    cout << " \nError: "<< res-sum << endl;
}
void cos(){
    cout << " You entered cos function"<<endl;
    float l;
    cout << "Input lower limit: ";
    cin >> l;
    float u;
    cout << "Input Upper limit: ";
    cin >> u;
    float n;
    cout << "Input n: ";
    cin >>n;
    u = u*3.1416/180;
    l = l*3.1416/180;
    float h = (u-l)/n;
    float sum =0;
    sum = 0.5*(cos(u)+cos(l));
    for(int i=1;i<n;i++)
    {
        sum = sum + cos(l+i*h);
    }
    sum*=h;
    cout << "\nActual result: " << sum;
    float res = sin(u)-sin(l);
    cout << "\nTheoritical resut: "<< res;
    cout << " \nError: "<< res-sum << endl;
    
}
void tan(){
    cout << " You entered tan function"<<endl;
    float l;
    cout << "Input lower limit: ";
    cin >> l;
    float u;
    cout << "Input Upper limit: ";
    cin >> u;
    float n;
    cout << "Input n: ";
    cin >>n;
    
    u = u*3.1416/180;
    l = l*3.1416/180;

    float h = (u-l)/n;

    float sum = 0.5*(tan(u)+tan(l));
    for(int i=1;i<n;i++)
    {
        sum = sum + tan(l+i*h);
    }
    sum*=h;
    cout << "\nActual result: " << sum;
    float res = -log(cos(u))+log(cos(l));
    cout << "\nTheoritical resut: "<< res;
    cout << " \nError: "<< res-sum << endl;
    
}
void log(){
    cout << " You entered log function"<<endl;
    float l;
    cout << "Input lower limit: ";
    cin >> l;
    float u;
    cout << "Input Upper limit: ";
    cin >> u;
    float n;
    cout << "Input n: ";
    cin >>n;
    float h = (u-l)/n;

    float sum = 0.5*(log(u)+log(l));
    for(int i=1;i<n;i++)
    {
        sum = sum + log(l+i*h);
    }
    sum*=h;
    cout << "\nActual result: " << sum;
    float res = (u*log(u)-u)-(l*log(l)-l);
    cout << "\nTheoritical resut: "<< res;
    cout << " \nError: "<< res-sum << endl;
}

int main()
{
    string s;
    cout << "Enter your Function: ";
    cin >> s;
    if (s == "sinx")
    {
        sin();
    }
    else if (s == "cosx")
    {
        cos();
    }
    else if (s == "logx")
    {
        log();
    }
    else if (s == "tanx")
    {
        tan();
    }
    else{
        cout << "Invalid Function";
    }
}