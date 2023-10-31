#include <iostream>

using namespace std;

typedef long long ll;

pair<int, int> two_five_cnt(int n) {
    int two_cnt = 0;
    int five_cnt = 0;

    for (ll i = 2; i <= n; i *= 2) two_cnt += n/i;
    for (ll i = 5; i <= n; i *= 5) five_cnt += n/i;
    return {two_cnt, five_cnt};
}

int main() {
    int n, m;
    int total_two_cnt, total_five_cnt;
    pair<int, int> total_cnt, m_cnt, nm_cnt;

    cin >> n >> m;
    
    total_cnt = two_five_cnt(n);
    m_cnt = two_five_cnt(m);
    nm_cnt = two_five_cnt(n - m);
    total_two_cnt = total_cnt.first - m_cnt.first - nm_cnt.first;
    total_five_cnt = total_cnt.second - m_cnt.second - nm_cnt.second;
    cout << min(total_two_cnt, total_five_cnt);
}