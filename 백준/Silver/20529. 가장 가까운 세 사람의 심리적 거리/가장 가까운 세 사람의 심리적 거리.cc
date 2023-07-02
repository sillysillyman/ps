#include <iostream>
#include <map>

using namespace std;

int sum_psychological_distance(string a, string b, string c) {
    int sum = 0;

    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i]) sum++;
        if (b[i] != c[i]) sum++;
        if (c[i] != a[i]) sum++;
    }
    return sum;
}

int main() {
    int T;
    int N;
    int ans;
    string mbti;
    map<string, int> mbtis;
    cin >> T;
    while (T--) {
        ans = ~(1 << 31);
        cin >> N;
        mbtis.clear();
        while (N--) {
            cin >> mbti;
            mbtis[mbti]++;
        }
        for (auto it1 = mbtis.begin(); it1 != mbtis.end(); it1++) {
            if (it1->second >= 3) {
                ans = 0;
                break;
            } else if (it1->second == 2) {
                for (auto it2 = it1; it2 != mbtis.end(); it2++) {
                    for (auto it3 = next(it2); it3 != mbtis.end(); it3++) {
                        ans = min(ans, sum_psychological_distance(it1->first, it2->first, it3->first));
                    }
                }
            } else {
                for (auto it2 = next(it1); it2 != mbtis.end(); it2++) {
                    if (it2->second == 2) {
                        for (auto it3 = it2; it3!= mbtis.end(); it3++) {
                            ans = min(ans, sum_psychological_distance(it1->first, it2->first, it3->first));
                        }
                    } else {
                        for (auto it3 = next(it2); it3 != mbtis.end(); it3++) {
                            ans = min(ans, sum_psychological_distance(it1->first, it2->first, it3->first));
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
}