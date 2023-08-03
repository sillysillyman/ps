#include <iostream>

using namespace std;

int main() {
    int A, B, N;
    int res;

    cin >> A >> B >> N;
    if (!(A%B)) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < N; i++) {
        A *= 10;
        res = A/B;
        res %= 10;
        A %= B;
    }
    cout << res;
}