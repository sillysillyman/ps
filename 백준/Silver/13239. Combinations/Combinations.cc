#include <iostream>

using namespace std;

// typedef long long ll;

const int MOD = 1000000007;
int dp[1001][1001];

int combination(int n, int k) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i) dp[i][j] = 1;
            else dp[i][j] = (dp[i - 1][j]%MOD + dp[i - 1][j - 1]%MOD)%MOD;
        }
    }
    return dp[n][k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, n, k;

    cin >> t;
    while (t--) {
        cin >> n >> k;
        cout << combination(n, k) << '\n';
    }
}