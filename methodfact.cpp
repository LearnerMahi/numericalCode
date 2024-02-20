#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <array>
#include <vector>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define pi 3.1415926536
#define div 1000003
#define mod 1000000009
#define MOD 998244353
#define N 10000005
#define fr(i,a,b) for(int i = a;i<b;i++)
#define fri(i,a,b) for(int i = a;i>=b;i--)
#define pb push_back
#define pyn(flag) cout<<(flag?"YES":"NO")<<endl;
#define vin cin>>v[i]
#define vsort sort(v.begin(), v.end())
#define vrev reverse(v.begin(), v.end())
#define yout cout<<"YES"<<endl
#define nout cout<<"NO"<<endl


vector<string> tokenize(const string& equation, char delimiter) {
    vector<string> tokens;
    stringstream ss(equation);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void luDecomposition(const vector<vector<int>>& A, vector<vector<double>>& L, vector<vector<double>>& U) {
    int n = A.size();
    L = vector<vector<double>>(n, vector<double>(n, 0.0));
    U = vector<vector<double>>(n, vector<double>(n, 0.0));

    for (int i = 0; i < n; i++) {
        L[i][i] = 1.0;
        for (int j = i; j < n; j++) {
            double sum = 0.0;
            for (int k = 0; k < i; k++) {
                sum += L[i][k] * U[k][j];
            }
            U[i][j] = A[i][j] - sum;
        }

        for (int j = i + 1; j < n; j++) {
            double sum = 0.0;
            for (int k = 0; k < i; k++) {
                sum += L[j][k] * U[k][i];
            }
            L[j][i] = (A[j][i] - sum) / U[i][i];
        }



    }

    cout << "Matrix L:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << L[i][j] << "\t";
            }
            cout << endl;
        }

        cout << "Matrix U:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << U[i][j] << "\t";
            }
            cout << endl;
        }
}


vector<double> solveSystem(const vector<vector<int>>& A, const vector<int>& B) {
    int n = A.size();
    vector<vector<double>> L, U;
    luDecomposition(A, L, U);


    vector<double> y(n, 0.0);
    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        for (int j = 0; j < i; j++) {
            sum += L[i][j] * y[j];
        }
        y[i] = (B[i] - sum) / L[i][i];
    }


    vector<double> x(n, 0.0);
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i + 1; j < n; j++) {
            sum += U[i][j] * x[j];
        }
        x[i] = (y[i] - sum) / U[i][i];
    }

    return x;
}

int main() {
    vector<string> equations;
    equations.push_back("2x + 3y + z = 9");
    equations.push_back("x + 2y + 3z = 6");
    equations.push_back("3x + y + 2z = 8");

    int n = equations.size();
    vector<vector<int>> A(n, vector<int>(n, 0));
    vector<int> B(n, 0);


    map<string, int> variablePosition;
    variablePosition["x"] = 0;
    variablePosition["y"] = 1;
    variablePosition["z"] = 2;


    for (int i = 0; i < n; i++) {
        vector<string> tokens = tokenize(equations[i], ' ');
        int m = tokens.size();
        for (int j = 0; j < m - 2; j++) {
            string token = tokens[j];
            int coefficient = 1;
            if (token.find("x") != string::npos || token.find("y") != string::npos || token.find("z") != string::npos) {

                string variable = token.substr(token.size() - 1, 1);
                coefficient = (token[0] == '-') ? -1 : 1;
                if (token[0] == '-' || token[0] == '+') {
                    token = token.substr(1);
                }
                if (token.size() > 1) {
                    coefficient *= stoi(token.substr(0, token.size() - 1));
                }
                A[i][variablePosition[variable]] = coefficient;
            }
        }
        B[i] = stoi(tokens[m - 1]);
    }

    vector<double> solution = solveSystem(A, B);

    cout << "Solution:" << endl;
    cout << "x = " << solution[0] << endl;
    cout << "y = " << solution[1] << endl;
    cout << "z = " << solution[2] << endl;


    return 0;
}

