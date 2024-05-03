#include <iostream>

using namespace std;

int main() {
    int N, X;

    cin >> N >> X;

    int *nums = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < N; i++) {
        if (nums[i] < X) cout << nums[i] << ' ';
    }
    delete[] nums;
}