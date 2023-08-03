#include <iostream>

using namespace std;

int rec_cnt = 0;
int dp_cnt = 0;
int dp[41];

int rec_fib(int n) {
    if (n == 1 || n == 2) {
        rec_cnt++;
        return 1;
    }
    else return rec_fib(n - 2) + rec_fib(n - 1);
}

int dp_fib(int n) {
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp_cnt++;
        dp[i] = dp[i - 2] + dp[i - 1];
    }
    return dp[n];
}

int main() {
    int n;

    cin >> n;
    rec_fib(n);
    dp_fib(n);
    cout << rec_cnt << ' ' << dp_cnt;
}