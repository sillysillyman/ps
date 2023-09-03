#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    string equality;

    getline(cin, equality);
    a = equality[0] - '0';
    b = equality[4] - '0';
    c = equality[8] - '0';
    if (a + b == c) cout << "YES";
    else cout << "NO";
}