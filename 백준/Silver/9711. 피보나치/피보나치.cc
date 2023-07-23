#include <iostream>

using namespace std;

long long dp[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T, P, Q;

    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> P >> Q;
        dp[0] = 0;
        dp[1] = 1%Q;
        for (int i = 2; i <= P; i++) dp[i] = (dp[i - 2] + dp[i - 1])%Q;
        cout << "Case #" << i << ": " << dp[P] << '\n';
    }
}