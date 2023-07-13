#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (a%b == 0) return b;
    else return (b, a%b);
}

int main() {
    int N;
    int gcd;
    int cnt = 0;

    cin >> N;

    vector<int> trees(N);
    vector<int> diff(N - 1);

    for (int i = 0; i < N; i++) cin >> trees[i];
    sort(trees.begin(), trees.end());
    for (int i = 0; i < N - 1; i++) {
        diff[i] = trees[i + 1] - trees[i];
        if (i == 0) gcd = diff[i];
        else gcd = get_gcd(gcd, diff[i]);
    }
    for (int i = 0; i < N - 1; i++) cnt += diff[i]/gcd - 1;
    cout << cnt;
}