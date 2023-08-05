#include <iostream>

using namespace std;

int main() {
    int minutes, seconds = 0;

    for (int i = 0; i < 4; i++) {
        int t;

        cin >> t;
        seconds += t;
    }
    minutes = seconds/60;
    seconds %= 60;
    cout << minutes << '\n' << seconds;
}