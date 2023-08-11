#include <iostream>

using namespace std;

int main() {
    int n, k;

    cin >> n;
    while (n--) {
        cin >> k;
        for (int i = 0; i < k; i++) cout << '=';
        cout << '\n';
    }
}