
/*
2x+3y+z+w=9
1x+2y+3z+4w=6
3x+y+2z=8
y+w=5
*/

#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long ll;

double A[5][5] , L[5][5] , U[5][5] , X[5][1] , Y[5][1];

void string_to_coefficient(string s , int i){
    int num = 0 ;
    int sign = 1 ;
    int idx = 0 ;
    if(s[0] == '-'){
        sign = -1 ;
        idx = 1 ;
    }
    for(int j = idx ; j < s.length() ; j++){
        if(s[j] <= '9' && s[j] >= '0'){
            num = num*10 + (s[j] - '0') ;
        }
        else if(s[j] == 'x'){
            if(num == 0) num = 1 ;
            A[i][1] = sign*num ;
            num = 0 ;
        }
        else if(s[j] == 'y'){
            if(num == 0) num = 1 ;
            A[i][2] = sign*num ;
            num = 0 ;
        }
        else if(s[j] == 'z'){
            if(num == 0) num = 1 ;
            A[i][3] = sign*num ;
            num = 0 ;
        }
        else if(s[j] == 'w'){
            if(num == 0) num = 1 ;
            A[i][4] = sign*num ;
            num = 0 ;
        }
    }
    X[i][0] = num ;
}

int main(){
    string s1 , s2 , s3 , s4;
    cin >> s1 >> s2 >> s3 >> s4 ;
    string_to_coefficient(s1 , 1) ;
    string_to_coefficient(s2 , 2) ;
    string_to_coefficient(s3 , 3) ;
    string_to_coefficient(s4 , 4) ;

    for(int i = 1 ; i <= 4 ; i++){
        for(int j = 1 ; j <= 4 ; j++){
            if(i == j){
                L[i][j] = 1 ;
            }
            else{
                L[i][j] = 0 ;
            }
            U[i][j] = 0 ;
        }
    }

    cout << "\nCoefficient : \n" ;
    for(int i = 1 ; i <= 4 ; i++){
        for(int j = 1 ; j <= 4 ; j++){
            cout << A[i][j] << " " ;
        }
        cout << "\t" << X[i][0] << endl ;
    }


    U[1][1] = A[1][1] ;
    U[1][2] = A[1][2] ;
    U[1][3] = A[1][3] ;
    U[1][4] = A[1][4] ;

    L[2][1] = A[2][1]/U[1][1] ;
    U[2][2] = A[2][2] - L[2][1]*U[1][2] ;
    U[2][3] = A[2][3] - L[2][1]*U[1][3] ;
    U[2][4] = A[2][4] - L[2][1]*U[1][4] ;

    L[3][1] = A[3][1]/U[1][1] ;
    L[3][2] = (A[3][2] - L[3][1]*U[1][2])/U[2][2] ;
    U[3][3] = A[3][3] - L[3][1]*U[1][3] - L[3][2]*U[2][3] ;
    U[3][4] = A[3][4] - L[3][1]*U[1][4] - L[3][2]*U[2][4] ;

    L[4][1] = A[4][1]/U[1][1] ;
    L[4][2] = (A[4][2] - L[4][1]*U[1][2])/U[2][2] ;
    L[4][3] = (A[4][3] - L[4][1]*U[1][3] - L[4][2]*U[2][3])/U[3][3] ;
    U[4][4] = A[4][4] - L[4][1]*U[1][4] - L[4][2]*U[2][4] - L[4][3]*U[3][4] ;

    cout << "\nLower Matrix : \n" ;
    for(int i = 1 ; i <= 4 ; i++){
        for(int j = 1 ; j <= 4 ; j++){
            cout << setw(10) << L[i][j] << " ";
        }
        cout << endl ;
    }
    cout << "\nUpper Matrix : \n" ;

    for(int i = 1 ; i <= 4 ; i++){
        for(int j = 1 ; j <= 4 ; j++){
            cout << setw(10) <<U[i][j] << " ";
        }
        cout << endl ;
    }

    Y[1][0] = X[1][0] ;
    Y[2][0] = X[2][0] - L[2][1]*Y[1][0] ;
    Y[3][0] = X[3][0] - L[3][1]*Y[1][0] - L[3][2]*Y[2][0] ;
    Y[4][0] = X[4][0] - L[4][1]*Y[1][0] - L[4][2]*Y[2][0] - L[4][3]*Y[3][0] ;

    cout << "\nY Matrix : \n" ;
    for(int i = 1 ; i <= 4 ; i++){
        cout << Y[i][0] << endl ;
    }

    double x , y , z , w ;
    w = Y[4][0]/U[4][4] ;
    z = (Y[3][0] - U[3][4]*w)/U[3][3] ;
    y = (Y[2][0] - U[2][3]*z - U[2][4]*w)/U[2][2] ;
    x = (Y[1][0] - U[1][2]*y - U[1][3]*z - U[1][4]*w)/U[1][1] ;

    cout << "\nSolutions : \n" ;
    cout << "x : " << x << endl ;
    cout << "y : " << y << endl ;
    cout << "z : " << z << endl ;
    cout << "w : " << w << endl ;

}
