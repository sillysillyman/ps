#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;

    cin >> N;

    vector<int> v(N);
    vector<int> dp(N);

    for (int i = 0; i < N; i++) cin >> v[i];
    for (int i = 0; i < N; i++) {
        dp[i] = v[i];
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) dp[i] = max(dp[i], dp[j] + v[i]);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}