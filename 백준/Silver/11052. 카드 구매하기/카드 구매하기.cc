#include <iostream>

using namespace std;

int cards[1001] = {};
int dp[1001] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> cards[i];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) dp[i] = max(dp[i], dp[i - j] + cards[j]);
    }
    cout << dp[N];
}