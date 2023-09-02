#include <iostream>

using namespace std;

const int MOD = 10007;
int dp[1001][10] = {};

int main() {
    int N;
    int res = 0;

    for (int i = 0; i < 10; i++) dp[1][i] = 1;
    for (int i = 2; i < 1001; i++) {
        for (int j = 0; j < 10; j++) {
            int sum = 0;

            for (int k = 0; k <= j; k++) {
                sum += dp[i - 1][k];
                sum %= MOD;
            }
            dp[i][j] = sum;
        }
    }
    cin >> N;
    for (int i = 0; i < 10; i++) {
        res += dp[N][i];
        res %= MOD;
    }
    cout << res;
}