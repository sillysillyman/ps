#include <iostream>
#include <vector>

using namespace std;

int N;
int min_num = 1000000000;
int max_num = -1000000000;
int operators[4];
vector<int> nums;

void dfs(int num, int idx) {
    if (idx == N) {
        if (num < min_num) min_num = num;
        if (num > max_num) max_num = num;
    } else {
        for (int i = 0; i < 4; i++) {
            if (operators[i] == 0) continue;
            operators[i]--;
            if (i == 0) dfs(num + nums[idx], idx + 1);
            else if (i == 1) dfs(num - nums[idx], idx + 1);
            else if (i == 2) dfs(num*nums[idx], idx + 1);
            else if (i == 3) dfs(num/nums[idx], idx + 1);
            operators[i]++;
        }
    }
}

int main() {
    int num;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        nums.push_back(num);
    }
    for (int i = 0; i < 4; i++) cin >> operators[i];
    dfs(nums[0], 1);
    cout << max_num << '\n' << min_num;
}