#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int units[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

vector<long long> make_decreasing_nums() {
    set<long long> decreasing_nums_set;
    
    for (int unit: units) {
        decreasing_nums_set.insert(unit);
    }
    for (auto decreasing_num: decreasing_nums_set) {
        for (auto unit: units) {
            if (decreasing_num%10 <= unit) continue;
            decreasing_nums_set.insert(decreasing_num*10 + unit);
        }
    }
    vector<long long> decreasing_nums(decreasing_nums_set.begin(), decreasing_nums_set.end());
    sort(decreasing_nums.begin(), decreasing_nums.end());
    return decreasing_nums;
}

int main() {
    int N;
    vector<long long> decreasing_nums = make_decreasing_nums();

    cin >> N;
    if (N > decreasing_nums.size() - 1) cout << -1;
    else cout << decreasing_nums[N];
}