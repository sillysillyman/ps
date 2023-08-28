#include <iostream>

using namespace std;

int main() {
    int len, colon = 0, underbar = 0;
    string chino_shock;

    cin >> chino_shock;
    len = chino_shock.length();
    for (auto c : chino_shock) {
        if (c == ':') colon++;
        else if (c == '_') underbar++;
    }
    cout << len + colon + 5*underbar;
}