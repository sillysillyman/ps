#include <iostream>

using namespace std;

int dp[1000001] = {};

int main() {
    int A, K;

    cin >> A >> K;
    for (int i = A; i <= K; i++) {
        if (dp[i] != 0) dp[i] = min(dp[i - 1] + 1, dp[i]);
        else if (i != A) dp[i] = dp[i - 1] + 1;
        if (2*i <= K) dp[2*i] = dp[i] + 1;
    }
    cout << dp[K];
}