#include <iostream>

using namespace std;

const int MOD = 9901;
int dp[100001][3];

int main() {
    int N;
    int res = 0;

    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;
    for (int i = 2; i < 100001; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2])%MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2])%MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1])%MOD;
    }
    cin >> N;
    for (int i = 0; i < 3; i++) res += dp[N][i];
    cout << res%MOD;
}