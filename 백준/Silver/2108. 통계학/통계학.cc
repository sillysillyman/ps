#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 8001;
int nums[MAX] = {};

int get_avg(int *nums, int n) {
    int avg;
    int sum = 0;

    for (int i = 0; i < MAX; i++) {
        sum += (i - MAX/2)*nums[i];
    }
    avg = round(float(sum)/n);
    avg = !avg ? abs(avg) : avg;
    return avg;
}

int get_median(int *nums, int n) {
    int cnt = 0;

    for (int i = 0; i < MAX; i++) {
        if (nums[i]) {
            for (int j = 0; j < nums[i]; j++) {
                if (cnt == n/2) return i - 4000;
                cnt++;
            }
        }
    }
}

int get_mode(int *nums, int n) {
    int mode;
    int mode_cnt = 0;
    bool second_mode = false;

    for (int i = 0; i < MAX; i++) {
        if (nums[i] > mode_cnt) mode_cnt = nums[i];
    }
    for (int i = 0; i < MAX; i++) {
        if (nums[i] == mode_cnt) {
            if (second_mode) {
                mode = i - 4000;
                break;
            }
            mode = i - 4000;
            second_mode = true;
        }
    }
    return mode;
}

int get_range(int *nums, int n) {
    int min, max;
    
    for (int i = 0; i < MAX; i++) {
        if (nums[i] > 0) {
            min = i - 4000;
            break;
        }
    }
    for (int i = MAX; i >= 0; i--) {
        if (nums[i] > 0) {
            max = i - 4000;
            break;
        }
    }
    return max - min;
}

int main() {
    int N;
    int num;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        nums[num + MAX/2]++;
    }
    cout << get_avg(nums, N) << endl;
    cout << get_median(nums, N) << endl;
    cout << get_mode(nums, N) << endl;
    cout << get_range(nums, N) << endl;
}