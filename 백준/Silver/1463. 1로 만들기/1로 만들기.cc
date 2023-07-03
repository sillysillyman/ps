#include <iostream>

using namespace std;

int dp[1000000] = {};

int main() {
    int N;
    
    dp[2] = 1;
    dp[3] = 1;
    cin >> N;
    for (int i = 4; i <= N; i++) {
        if (i%2 != 0 && i%3 != 0) dp[i] = dp[i - 1] + 1;
        else {
            if (i%2 == 0 && i%3 == 0) dp[i] = min(dp[i/2], dp[i/3]) + 1;
            else if (i%2 == 0) dp[i] = min(dp[i/2], dp[i - 1]) + 1;
            else if (i%3 == 0) dp[i] = min(dp[i/3], dp[i - 1]) + 1;
        }
    }
    cout << dp[N];
}