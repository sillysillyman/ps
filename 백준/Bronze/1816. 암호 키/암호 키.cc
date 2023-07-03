#include <iostream>

using namespace std;

bool is_password_key(long long s) {
    for (int i = 2; i <= 1000000; i++) {
        if (s%i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    long long S;

    cin >> N;
    while (N--) {
        cin >> S;
        if (is_password_key(S)) cout << "YES\n";
        else cout << "NO\n";
    }
}