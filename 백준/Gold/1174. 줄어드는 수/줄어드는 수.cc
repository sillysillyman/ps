#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

string digits = "9876543210";
vector<ll> v;

void make_decreasing_number(int idx, string s) {
    if (idx > 9) return;
    for (int i = idx; i < 10; i++) {
        string t = s;
        
        t.push_back(digits[i]);
        v.push_back(stoll(t));
        make_decreasing_number(i + 1, t);

    }
}

int main() {
    int N;

    cin >> N;
    make_decreasing_number(0, "");
    sort(v.begin(), v.end());
    if (N > v.size()) cout << -1;
    else cout << v[N - 1];
}