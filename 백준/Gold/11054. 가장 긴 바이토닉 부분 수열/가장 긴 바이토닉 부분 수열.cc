#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, num;
    int lis_v[1000];
    int lis_w[1000];
    vector<int> v;
    vector<int> w;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        v.push_back(num);
        w.push_back(num);
    }
    reverse(w.begin(), w.end());
    for (int i = 0; i < N; i++) {
        lis_v[i] = 1;
        lis_w[i] = 1;
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) lis_v[i] = max(lis_v[i], lis_v[j] + 1);
            if (w[j] < w[i]) lis_w[i] = max(lis_w[i], lis_w[j] + 1);
        }
    }
    int max_bitonic_len = 0;

    // cout << endl;
    // for (int i = 0; i < N; i++) cout << lis_v[i] << ' ';
    // cout << endl;
    // for (int i = 0; i < N; i++) cout << lis_w[i] << ' ';
    // cout << endl;

    for (int i = 0; i < N; i++) {
        max_bitonic_len = max(max_bitonic_len, lis_v[i] + lis_w[N - i - 1] - 1);
    }
    cout << max_bitonic_len;
}
// 1 5 2 1 4 3 4 5 2 1
// 1 2 2 2 3 3 4 5 5 5

// 1 2 5 4 3 4 1 2 5 1
// 1 2 3 3 3 4 4 4 5 5