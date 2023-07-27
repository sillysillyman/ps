#include <iostream>

using namespace std;

int main() {
    int N;
    string S;

    cin >> N;
    while (N--) {
        cin >> S;
        for (int i = 0; i < S.length(); i++) {
            if (isupper(S[i]))  S[i] = tolower(S[i]);
        }
        cout << S << '\n';
    }
}