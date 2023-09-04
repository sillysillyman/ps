#include <iostream>
#include <vector>

using namespace std;

int nums[2000001] = {};

int main() {
    int N;
    int S[20];
    vector<int> v;

    cin >> N;
    for (int i = 0; i < N; i++) cin >> S[i];
    for (int i = 1; i < (1<<N); i++) {
        int sum = 0;

        for (int j = 0; j < N; j++) {
            if (i&(1<<j)) sum += S[j];
        }
        v.push_back(sum);
    }
    for (auto i : v) nums[i] = 1;
    for (int i = 1; i < 2000001; i++) {
        if (nums[i] == 0) {
            cout << i;
            break;
        }
    }
}