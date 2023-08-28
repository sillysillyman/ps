#include <iostream>

using namespace std;

typedef long long ll;

const int MOD = 10007;
ll dp[1001][1001];

int main() {
    int N, K;

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= min(i, K); j++) {
            if (j == 0 || j == i) dp[i][j] = 1;
            else dp[i][j] = (dp[i - 1][j]%MOD + dp[i - 1][j - 1]%MOD)%MOD;
        }
    }
    cout << dp[N][K];
}