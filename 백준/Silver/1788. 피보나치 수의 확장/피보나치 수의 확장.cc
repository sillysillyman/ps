#include <iostream>
#include <cstdlib>

using namespace std;

const int mod = 1000000000;
long long dp[1000000];

int main() {
    int n;
    
    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= abs(n); i++) dp[i] = (dp[i - 2] + dp[i - 1])%mod;
    if (n > 0) {
        cout << 1 << endl;
        cout << dp[n];
    } else if (n < 0) {
        if (abs(n)%2) cout << 1 << endl;
        else cout << -1 << endl;
        cout << dp[abs(n)];
    } else {
        cout << 0 << '\n' << 0;
    }
}