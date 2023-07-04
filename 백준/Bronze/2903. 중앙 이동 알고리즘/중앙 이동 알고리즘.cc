#include <iostream>

using namespace std;

int main() {
    int N;
    int n = 2;
    int exp = 1;

    cin >> N;
    while (N--) {
        n += exp;
        exp *= 2;
    }
    cout << n*n;
}