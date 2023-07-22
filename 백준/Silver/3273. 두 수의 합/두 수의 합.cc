#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    int cnt = 0;

    cin >> n;
    
    vector<int> nums(n);
    
    for (int i = 0; i < n; i++) cin >> nums[i];
    cin >> x;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((nums[i] + nums[j]) == x) cnt++;
            else if ((nums[i] + nums[j]) > x) break;

        }
        if (nums[i] > x) break;
    }
    cout << cnt;
}