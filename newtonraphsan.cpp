#include<bits/stdc++.h>
using namespace std;
vector<double> stringToCoefficient(string s){
    vector<double>coefficient;
    regex r("(-?\\d*)x\\^(\\d+)");
    smatch m;
    while (regex_search(s,m,r)){
        string coeff=m[1];
        string exp=m[2];
        if(coeff.empty()) coeff="1";
        int cop=stoi(coeff);
        coefficient.push_back(cop);
        s=m.suffix();
    }
    return coefficient;
}
double f(vector<double>coefficient,double x){
    int degree=coefficient.size()-1;
    double result=0.0;
    for (int  i = 0; i<=degree; i++){
        result+=coefficient[i]*pow(x,degree-i);

    }
    return result; 
}
vector<double> derivation(vector<double> coefficient){
    int n=coefficient.size();
    vector<double>derive(n-1);
    for(int i=0;i<n-1;i++){
        derive[i]=coefficient[i]*(n-1-i);
    }
    return derive;
}
void newtonRaphson(vector<double>coefficient,double x){
    vector<double>deri=derivation(coefficient);
    double h;
    int iter=0;
    do{
        h=f(coefficient,x)/f(deri,x);
        x=x-h;
        iter++;
        }while(fabs(h)>=0.001);
            cout<<"Root is "<<x<<endl;
            cout<<"No of iteration "<<iter<<endl;
        
}
int main()
{
    string s="4x^3+3x^2+4x^1+4x^0";
    vector<double>coefficient=stringToCoefficient(s);
    cout<<"Initial value: "<<endl;
    double x;
    cin>>x;
    newtonRaphson(coefficient,x);
}