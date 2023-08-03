#include <iostream>

using namespace std;

int main() {
    string s, t;

    cin >> s >> t;
    if (s.length() < t.length()) cout << "no";
    else cout << "go";
}