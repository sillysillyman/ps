#include <iostream>

using namespace std;

typedef long long ll;

const int MOD = 1000000009;
int dp[1000001] = {0, 1, 2, 4,};

int main() {
    int T, n;

    cin >> T;
    for (int i = 4; i < 1000001; i++) dp[i] = ((ll)dp[i - 3]%MOD + (ll)dp[i - 2]%MOD + (ll)dp[i - 1]%MOD)%MOD;
    while (T--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
}