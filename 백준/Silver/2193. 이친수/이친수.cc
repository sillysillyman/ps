#include <iostream>
#include <vector>
#include <map>

using namespace std;

// map<int, vector<int>> dp;
long long dp[91];

int main() {
    int N;

    cin >> N;
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 2] + dp[i - 1];
    }
    cout << dp[N];
}
// 1: 1 -> 1
// 2: 10 -> 1
// 3; 100, 101 -> 2
// 4: 1000, 1001, 1010 -> 3
// 5: 10000, 10001, 10010, 10100, 10101 -> 5
// 6: 100000, 100001, 100010, 100100, 101000, 100101, 101001, 101010 -> 7