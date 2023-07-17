#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> primes;

void eratos(int n) {
    primes[0] = false;
    primes[1] = false;
    for (int i = 2; i < n + 1; i++) {
        if (primes[i]) {
            for (int j = 2; i*j < n + 1; j++) primes[i*j] = false;
        }  
    }
}

int get_partition(int n) {
    int cnt = 0;

    for (int i = 2; i <= n/2; i++) {
        if (primes[i] && primes[n - i]) cnt++;
    }
    return cnt;
}

int main() {
    int T, N;
    vector<int> nums;

    cin >> T;
    primes.assign(1000001, true);
    while (T--) {
        cin >> N;
        nums.push_back(N);
    }

    int max_num = *max_element(nums.begin(), nums.end());

    eratos(max_num);
    for (auto num : nums) cout << get_partition(num) << '\n';
}