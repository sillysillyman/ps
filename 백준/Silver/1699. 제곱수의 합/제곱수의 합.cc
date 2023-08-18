#include <iostream>
#include <cmath>

using namespace std;

int dp[100001] = {};

bool is_squared(int n) {
    return (int)sqrt(n) == sqrt(n);
}

int main() {
    int N;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        dp[i] = i;
        if (is_squared(i)) dp[i] = 1;
        else {
            for (int j = 1; j*j < i; j++) dp[i] = min(dp[i], dp[i - j*j] + 1);
        }
    }
    cout << dp[N];
}