#include <iostream>

using namespace std;

int main() {
    int N, L;

    cin >> N >> L;

    for (int i = L; i <= 100; i++) {
        int num = (2*N - i*(i - 1))/(2*i);
        int r = (2*N - i*(i - 1))%(2*i);
        if (r < 0 || num < 0) {
            cout << -1;
            return 0;
        }
        if (r == 0) {
            for (int j = 0; j < i; j++) {
                cout << num + j << " ";
            }
            return 0;
        }
    }
    cout << -1;
}