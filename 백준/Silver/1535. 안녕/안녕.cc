#include <iostream>

using namespace std;

int main() {
    int N;
    int losses[20], joys[20];
    int dp[101] = {};

    cin >> N;
    for (int i = 0; i < N; i++) cin >> losses[i];
    for (int i = 0; i < N; i++) cin >> joys[i];
    for (int i = 0; i < N; i++) {
        for (int j = 100; j >= losses[i]; j--) dp[j] = max(dp[j], dp[j - losses[i]] + joys[i]);
    }
    cout << dp[99];
}