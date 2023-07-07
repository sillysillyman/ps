#include <iostream>

using namespace std;

int main() {
    int S = 0, T = 0;
    int score;

    for (int i = 0; i < 4; i++) {
        cin >> score;
        S += score;
    }
    for (int i = 0; i < 4; i++) {
        cin >> score;
        T += score;
    }
    S >= T ? cout << S : cout << T;
}