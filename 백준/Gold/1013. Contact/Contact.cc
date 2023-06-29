#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    int T;
    string bits;
    regex pattern("(100+1+|01)+");

    cin >> T;

    while (T--) {
        cin >> bits;
        cout << (regex_match(bits, pattern) ? "YES\n" : "NO\n");
    }
}