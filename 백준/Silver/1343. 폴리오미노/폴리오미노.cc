#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;

    cin >> s;
    for (int i = 0; i < s.length();) {
        if (s.substr(i, 4) == "XXXX") {
            s.replace(i, 4, "AAAA");
            i += 4;
        } else if (s.substr(i, 2) == "XX") {
            s.replace(i, 2, "BB");
            i += 2;
        } else i++;
    }
    for (auto c : s) {
        if (c == 'X') {
            cout << -1;
            return 0;
        }
    }
    cout << s;
}