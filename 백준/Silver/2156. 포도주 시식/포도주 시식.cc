#include <iostream>
#include <algorithm>

using namespace std;

int wines[10000];
int dp[10000];

int main() {
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> wines[i];
    dp[0] = wines[0];
    dp[1] = dp[0] + wines[1];
    dp[2] = max(dp[0] + wines[2], max(wines[1] + wines[2], dp[1]));
    for (int i = 3; i < n; i++) dp[i] = max(dp[i - 2] + wines[i], max(dp[i - 3] + wines[i - 1] + wines[i], dp[i - 1]));
    cout << *max_element(dp, dp + n) << endl;
}