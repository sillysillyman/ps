#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    int num;
    vector<int> nums;

    cin >> N;
    while (N--) {
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    cin >> M;
    while (M--) {
        cin >> num;
        cout << binary_search(nums.begin(), nums.end(), num) << '\n';
    }
}