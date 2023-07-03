#include <iostream>
#include <cmath>

using namespace std;

int nums[10000001] = {};

bool is_prime(int num) {
    if (num <= 1) return false;
    else if (num <= 3) return true;
    else if (num%2 == 0) return false;
    else {
        int root = int(sqrt(num));
        
        for (int i = 3; i <= root; i++) {
            if (num%i == 0) return false;
        }
    }
    return true;
}

void delete_not_prime(int max) {
    nums[1] = 0;
    for (int num : nums) {
        if (num == max) break;
        if (!num) continue;
        else {
            if (is_prime(num)) {
                int time = 2;
                
                while (1) {
                    if (num*time > max) break;
                    nums[num*time] = 0;
                    time++;
                }
            }
        }
    }
    return;
}

int main() {
    int M, N;

    cin >> M >> N;
    for (int i = 0; i <= N; i++) {
        nums[i] = i;
    }
    delete_not_prime(N);
    for (int i = M; i <= N; i++) {
        if (nums[i]) cout << nums[i] << '\n';
    }
}