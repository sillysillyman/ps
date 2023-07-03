#include <iostream>
#include <algorithm>

int nums[100000];

using namespace std;

int main() {
    int n;
    int num;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (i == 0) nums[i] = num;
        else nums[i] = max(num, nums[i - 1] + num);
    }
    sort(nums, nums + n, greater<>());
    cout << nums[0];
}