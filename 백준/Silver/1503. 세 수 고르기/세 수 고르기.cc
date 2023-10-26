#include <iostream>
#include <cmath>

using namespace std;

int nums[1002];

int main() {
    int N, M;

    cin >> N >> M;
    if (M == 0) {
        cout << 0;
        return 0;
    }
    fill(nums + 1, nums + 1002, 1);
    for (int i = 0; i < M; i++) {
        int num;

        cin >> num;
        nums[num] = 0;
    }

    int min_num = ~(1<<31);

    for (int i = 1; i < 1002; i++) {
        if (!nums[i]) continue;
        for (int j = i; j < 1002; j++) {
            if (!nums[j]) continue;
            for (int k = j; k < 1002; k++) {
                if (!nums[k]) continue;
                min_num = min(min_num, abs(N - i*j*k));
                if (min_num == 0) {
                    cout << 0;
                    return 0;
                }
            }
        }
    }
    cout << min_num;
}