#include <iostream>

using namespace std;

const int MAX_INT = ~(1<<31);

int main() {
    int n;
    int dp[50001] = {};

    cin >> n;
    dp[1] = 1;
    for (int i = 1; i <= n; i++) {
        int min_n = MAX_INT;

        for (int j = 1; j*j <= i; j++) min_n = min(min_n, dp[i - j*j]);
        dp[i] = min_n + 1;
    }
    cout << dp[n];
}