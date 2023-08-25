#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

const int MOD = 1000000007;
matrix mat = {{1, 1}, {1, 0}};

matrix operator * (matrix m1, matrix m2) {
    matrix ret(2, vector<ll> (2));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int num = 0;

            for (int k = 0; k < 2; k++) num += ((m1[i][k]%MOD)*(m2[k][j]%MOD))%MOD;
            ret[i][j] = num%MOD;
        }
    }
    return ret;
}

matrix pow(matrix m, ll e) {
    if (e == 1) return m;
    else if (e == 2) return m*m;

    matrix res = pow(m, e/2);

    if (e%2) return res*res*m;
    else return res*res;
}

int main() {
    ll n;
    matrix res;

    cin >> n;
    res = pow(mat, n);
    cout << res[0][1];
}