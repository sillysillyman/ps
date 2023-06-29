#include <iostream>

using namespace std;

int combination(int n, int r) {
    if (r == 0) {
        return 1;
    }
    if (n - r < r) {
        return combination(n, n - r);
    } else {
        long long numerator = n;
        long long denominator = r;
        while (--r) {
            numerator *= --n;
            denominator *= r;
        }
        return numerator/denominator;
    }
}

int main() {
    int T;
    int N, M;
    
    cin >> T;

    while (T--) {
        cin >> N >> M;
        if (N > M) {
            cout << combination(N, M) << endl;
        } else {
            cout << combination(M, N) << endl;
        }
    }
}