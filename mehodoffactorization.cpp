
/*
2x+3y+z+w=9
1x+2y+3z+4w=6
3x+y+2z=8
y+w=5
*/#include<bits/stdc++.h>
using namespace std;

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

    // Perform LU decomposition with pivoting
    for(int i = 1 ; i <= 4 ; i++){
        for(int j = i ; j <= 4 ; j++){
            U[i][j] = A[i][j];
            for(int k = 1 ; k <= i-1 ; k++){
                U[i][j] -= L[i][k]*U[k][j];
            }
        }
        for(int j = i+1 ; j <= 4 ; j++){
            L[j][i] = A[j][i];
            for(int k = 1 ; k <= i-1 ; k++){
                L[j][i] -= L[j][k]*U[k][i];
            }
            L[j][i] /= U[i][i];
        }
    }

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
            cout << setw(10) << U[i][j] << " ";
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
/*
cpp
Copy code
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long ll;
These lines include necessary headers and define some shortcuts for coding convenience. #include<bits/stdc++.h> is a common way to include most standard C++ headers. fast is defined to optimize input/output operations, and typedef long long ll defines ll as a shorthand for long long.
cpp
Copy code
double A[5][5] , L[5][5] , U[5][5] , X[5][1] , Y[5][1];
These lines declare various matrices and arrays used in the program:
A is a 2D array to store coefficients of the equations.
L is a 2D array for the lower triangular matrix in the LU decomposition.
U is a 2D array for the upper triangular matrix in the LU decomposition.
X is a 2D array to store the right-hand side of the equations.
Y is a 2D array to store intermediate results during the LU decomposition.
cpp
Copy code
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
This function string_to_coefficient takes an equation string s and an index i as input.
It parses the equation string and extracts coefficients for the variables x, y, z, and w, as well as the constant term.
The coefficients are then stored in the appropriate positions in the A matrix, and the constant term is stored in the X matrix.
cpp
Copy code
int main(){
    string s1 , s2 , s3 , s4;
    cin >> s1 >> s2 >> s3 >> s4 ;
    string_to_coefficient(s1 , 1) ;
    string_to_coefficient(s2 , 2) ;
    string_to_coefficient(s3 , 3) ;
    string_to_coefficient(s4 , 4) ;
In the main function, four equation strings s1, s2, s3, and s4 are read from the user.
The string_to_coefficient function is called four times, once for each equation, to extract coefficients from the equation strings and store them in the A and X matrices.
cpp
Copy code
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
This loop initializes the L matrix as an identity matrix and the U matrix as all zeros. The L matrix starts as an identity matrix because the diagonal elements are set to 1, which is the initial value for LU decomposition.
cpp
Copy code
// Perform LU decomposition with pivoting
for(int i = 1 ; i <= 4 ; i++){
    for(int j = i ; j <= 4 ; j++){
        U[i][j] = A[i][j];
        for(int k = 1 ; k <= i-1 ; k++){
            U[i][j] -= L[i][k]*U[k][j];
        }
    }
    for(int j = i+1 ; j <= 4 ; j++){
        L[j][i] = A[j][i];
        for(int k = 1 ; k <= i-1 ; k++){
            L[j][i] -= L[j][k]*U[k][i];
        }
        L[j][i] /= U[i][i];
    }
}
These loops perform the LU decomposition with pivoting. They calculate the L and U matrices.
The outer loop iterates through rows (i) from 1 to 4.
The first inner loop calculates elements of the upper matrix (U) while the second inner loop calculates elements of the lower matrix (L).
Pivoting is performed by dividing each element of the L matrix by the corresponding diagonal element of the U matrix (U[i][i]) to ensure stability.
cpp
Copy code
Y[1][0] = X[1][0] ;
Y[2][0] = X[2][0] - L[2][1]*Y[1][0] ;
Y[3][0] = X[3][0] - L[3][1]*Y[1][0] - L[3][2]*Y[2][0] ;
Y[4][0] = X[4][0] - L[4][1]*Y[1][0] - L[4][2]*Y[2][0] - L[4][3]*Y[3][0] ;
These lines calculate the intermediate results for the Y matrix. It's essentially the forward substitution step in the LU decomposition.
cpp
Copy code
double x , y , z , w ;
w = Y[4][0]/U[4][4] ;
z = (Y[3][0] - U[3][4]*w)/U[3][3] ;
y = (Y[2][0] - U[2][3]*z - U[2][4]*w)/U[2][2] ;
x = (Y[1][0] - U[1][2]*y - U[1][3]*z - U[1][4]*w)/U[1][1] ;
These lines calculate the values of x, y, z, and w by back-substitution using the Y, L, and U matrices.
cpp
Copy code
cout << "\nSolutions : \n" ;
cout << "x : " << x << endl ;
cout << "y : " << y << endl ;
cout << "z : " << z << endl ;
cout << "w : " << w << endl ;
Finally, the code prints out the solutions for the variables x, y, z, and w.
This code essentially performs LU decomposition with pivoting to solve a system of linear equations with four variables. The main steps include parsing the equations, constructing the L and U matrices, and performing forward and backward substitution to obtain the solutions.
*/
