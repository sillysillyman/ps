#include <iostream>

using namespace std;

int main() {
    int N;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cout << i << " ";
        if (i == N) break;
        if (i%6 == 0) cout << "Go! ";
    }
    cout << "Go! ";
}