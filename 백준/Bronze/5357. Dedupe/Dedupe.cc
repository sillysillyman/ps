#include <iostream>

using namespace std;

int main() {
    int N;
    string str;

    cin >> N;
    while (N--) {
        cin >> str;
        for (int i = 0; i < str.length(); i++) {
            if (i == 0) cout << str[i];
            else if (str[i] != str[i - 1]) cout << str[i];
        }
        cout << '\n';
    }
}