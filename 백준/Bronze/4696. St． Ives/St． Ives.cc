#include <iostream>

using namespace std;

int main() {
    double n, res;

    while (true) {
        cin >> n;
        if (n == 0) break;
        cout << fixed;
        cout.precision(2);
        res = 1 + n + n*n + n*n*n + n*n*n*n;
        cout << res << '\n';
    }
}