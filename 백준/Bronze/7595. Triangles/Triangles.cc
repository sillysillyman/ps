#include <iostream>

using namespace std;

void triangle(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) cout << '*';
        cout << '\n';
    }
}

int main() {
    int n;

    while (true) {
        cin >> n;
        if (n == 0) break;
        triangle(n);
    }
}