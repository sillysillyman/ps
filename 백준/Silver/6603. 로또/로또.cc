#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool has_six_digits(int n) {
    int cnt = 0;
    while (n > 0) {
        if (n&1) cnt++;
        n >>= 1;
    }
    if (cnt == 6) return true;
    else return false;
}

int main() {
    int k;

    while (true) {
        cin >> k;
        if (k == 0) break;
        
        vector<int> v(k);
        vector<vector<int>> lottos;

        for (int i = 0; i < k; i++) cin >> v[i];
        for (int i = 0; i < (1<<k); i++) {
            if (!has_six_digits(i)) continue;
            
            vector<int> lotto;

            for (int j = 0; j < k; j++) {
                if (i&(1<<j)) lotto.push_back(v[j]);
            }
            lottos.push_back(lotto);
        }
        sort(lottos.begin(), lottos.end());
        for (auto i : lottos) {
            for (auto j: i) cout << j << ' ';
            cout << '\n';
        }
        cout << '\n';
    }
}