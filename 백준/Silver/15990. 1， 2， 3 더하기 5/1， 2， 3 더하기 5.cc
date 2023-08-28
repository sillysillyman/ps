#include <iostream>

using namespace std;

typedef long long ll;

const int MOD = 1000000009;
int dp[100001][4] = {};

int main() {
    int T, n;

    cin >> T;
    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    for (int i = 4; i < 100001; i++) {
        dp[i][1] = (dp[i - 1][2]%MOD + dp[i - 1][3]%MOD)%MOD;
        dp[i][2] = (dp[i - 2][1]%MOD + dp[i - 2][3]%MOD)%MOD;
        dp[i][3] = (dp[i - 3][1]%MOD + dp[i - 3][2]%MOD)%MOD;
    }
    while (T--) {
        cin >> n;
        cout << ((ll)dp[n][1] + (ll)dp[n][2] + (ll)dp[n][3])%MOD << '\n';
    }
}