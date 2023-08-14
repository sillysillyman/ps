#include <iostream>
#include <map>

using namespace std;

int nums[1000000];
int accumulated[1000000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    long long cnt = 0;
    map<int, int> m;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
        if (i == 0) accumulated[i] = nums[i]%M;
        else accumulated[i] = (accumulated[i - 1] + nums[i])%M;
        if (accumulated[i] == 0) cnt++;
        m[accumulated[i]]++;
    }
    // for (int i = 0; i < N; i++) cout << accumulated[i] << ' ';
    // cout << endl;
    for (auto i : m) cnt += (long long)i.second*(i.second - 1)/2;
    cout << cnt;
}
// 1 2 3 1 2
// 1 3 6 7 9
// 1 0 0 1 0
// [l, r]
// sum = (accumulated[r] -  accumulated[l - 1])%M = 0
// sum = (accumulated[r]%M - accumulated[l - 1]%M)%M = 0
// sum = accumulated[r]%M - accumulated[l - 1]%M = 0