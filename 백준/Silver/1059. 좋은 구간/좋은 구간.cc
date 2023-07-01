#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int L, e, n;
    vector<int> S;
    int cnt = 0;

    cin >> L;
    while (L--) {
        cin >> e;
        S.push_back(e);
    }
    sort(S.begin(), S.end());
    cin >> n;

    int under_bound = 0;
    int upper_bound;

    for (int num: S) {
        if (n > num) under_bound = num;
        else if (n == num) {
            cout << 0;
            return 0;
        } else {
            upper_bound = num;
            break;
        }
    }
    under_bound++;
    upper_bound--;
    for (int i = under_bound; i < upper_bound; i++) {
        for (int j = i + 1; j <= upper_bound; j++) {
            if ((i <= n)&&(n <= j)) cnt++;
        }
    }
    cout << cnt;
}