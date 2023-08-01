#include <iostream>

using namespace std;

int main() {
    int n;
    long long dp[51];

    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) dp[i] = (dp[i - 2] + dp[i - 1] + 1)%1000000007;
    cout << dp[n];
}