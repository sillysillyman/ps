#include <iostream>

using namespace std;

int main() {
    int N;
    int cnt;

    while (true) {
        cin >> N;
        cnt = 0;
        if (N == 0) break;
        for (int i = 1; i <= N; i++) cnt += i;
        cout << cnt << endl;
    }
}