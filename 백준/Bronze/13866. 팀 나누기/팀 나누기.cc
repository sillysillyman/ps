#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int skills[4];

    for (int i = 0; i < 4; i++) cin >> skills[i];
    sort(skills, skills + 4);
    cout << abs(skills[0] - skills[1] - skills[2] + skills[3]);
}