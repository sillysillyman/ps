#include <iostream>
#include <algorithm>

using namespace std;

int nums[2250000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;

    cin >> N;
    for (int i = 0; i < N*N; i++) cin >> nums[i];
    sort(nums, nums + N*N, greater<>());
    cout << nums[N - 1];
}