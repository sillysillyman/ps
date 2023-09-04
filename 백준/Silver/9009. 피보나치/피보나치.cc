#include <iostream>
#include <vector>

using namespace std;

vector<int> fibo;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n;

    fibo.push_back(0);
    fibo.push_back(1);
    while (true) {
        int num = *(fibo.end() - 2) + *(fibo.end() - 1);

        if (num > 1000000000 || num < 0) break;
        fibo.push_back(num);
    }
    cin >> T;
    while (T--) {
        cin >> n;

        string res = "";

        for (int i = fibo.size() - 1; i >= 0; i--) {
            if (n == 0) break;
            if (fibo[i] > n) continue;
            n -= fibo[i];
            res = to_string(fibo[i]) + " " + res;
        }
        cout << res << '\n';
    }
}