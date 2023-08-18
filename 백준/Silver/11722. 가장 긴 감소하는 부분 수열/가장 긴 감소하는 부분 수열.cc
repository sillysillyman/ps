#include <iostream>
#include <algorithm>

using namespace std;

int nums[1000];
int dp[1000];

int main() {
    int N;

    cin >> N;
    for (int i = 0; i < N; i++) cin >> nums[i];
    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[j] > nums[i]) dp[i] = max(dp[i], dp[j] + 1); 
        }
    }
    cout << *max_element(dp, dp + N);
}