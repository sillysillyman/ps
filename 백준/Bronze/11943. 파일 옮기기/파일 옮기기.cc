#include <iostream>

using namespace std;

int main() {
    int basket1[2], basket2[2];

    cin >> basket1[0] >> basket1[1];
    cin >> basket2[0] >> basket2[1];
    cout << min(basket1[0] + basket2[1], basket1[1] + basket2[0]);
}