#include <iostream>

using namespace std;

int main() {
    int R, C, W;
    int sum = 0;
    int dp[30][30];

    cin >> R >> C >> W;
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (j == 0 || j == i) dp[i][j] = 1;
            else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    for (int k = 0; k < W;) {
        for (int i = R - 1; i < R + W - 1; i++) {
            for (int j = C - 1; j < C + k; j++) sum += dp[i][j];
            k++;
        }
    }
    cout << sum;
}