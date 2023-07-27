#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    int curr_max;
    int nums[1000];
    int len_of_subsequence[1000] = {};

    cin >> N;
    for (int i = 0; i < N; i++) cin >> nums[i];
    curr_max = nums[0];
    len_of_subsequence[0] = 1;
    for (int i = 1; i < N; i++) {
        curr_max = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (nums[j] < nums[i] && len_of_subsequence[j] > curr_max) {
                len_of_subsequence[i] = len_of_subsequence[j] + 1;
                curr_max = len_of_subsequence[j];
            }
        }
        if (len_of_subsequence[i] == 0) len_of_subsequence[i] = 1;
    }
    // cout << endl;
    // for (int i = 0; i < N; i++) cout << len_of_subsequence[i] << ' ';
    cout << *max_element(len_of_subsequence, len_of_subsequence + N);
}
// 9
// 90 100 10 30 20 50 10 110 120
// 1  2   1  2  2  3  1  4   5