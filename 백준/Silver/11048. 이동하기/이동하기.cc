#include <iostream>

using namespace std;

int maze[1000][1000] = {};
int dp[1000][1000] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> maze[i][j];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == 0 && j == 0) dp[i][j] = maze[i][j];
            else if (i == 0) dp[i][j] = dp[i][j - 1] + maze[i][j];
            else if (j == 0) dp[i][j] = dp[i - 1][j] + maze[i][j];
            else dp[i][j] = max(dp[i][j - 1], max(dp[i - 1][j], dp[i - 1][j - 1])) + maze[i][j];
        }
    }
    cout << dp[N - 1][M - 1];
}