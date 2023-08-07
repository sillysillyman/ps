#include <iostream>

using namespace std;

const int MODULER = 1000000000;

int main() {
    int N;
    long long dp[101][10] = {};
    
    cin >> N;
    for (int i = 1; i < 10; i++) dp[1][i] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) dp[i][j] = dp[i - 1][j + 1]%MODULER;
            else if (j == 9) dp[i][j] = dp[i - 1][j - 1]%MODULER;
            else dp[i][j] = (dp[i - 1][j - 1]%MODULER + dp[i - 1][j + 1]%MODULER)%MODULER;
        }
    }

    long long sum = 0;

    for (int i = 0; i < 10; i++) sum += (dp[N][i]%MODULER);
    cout << sum%MODULER;
}