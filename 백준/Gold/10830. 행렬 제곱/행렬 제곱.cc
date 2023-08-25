#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<vector<int>> matrix;

const int MOD = 1000;
matrix mat(5, vector<int> (5));

matrix operator * (matrix m1, matrix m2) {
    int n = m1.size();
    matrix ret(n, vector<int> (n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num = 0;
            
            for (int k = 0; k < n; k++) num += ((m1[i][k]%MOD)*(m2[k][j]%MOD))%MOD;
            ret[i][j] = num%MOD;
        }
    }
    return ret;
}

matrix pow(matrix m, ll b) {
    if (b == 1) return m;
    else if (b == 2) return m*m;
    
    matrix res = pow(m, b/2);
    
    if (b%2) return res*res*m;
    else return res*res;
}

int main() {
    int N;
    ll B;

    cin >> N >> B;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
            mat[i][j] %= MOD;
        }
    }

    matrix res = pow(mat, B);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << res[i][j] << ' ';
        cout << '\n';
    }
}