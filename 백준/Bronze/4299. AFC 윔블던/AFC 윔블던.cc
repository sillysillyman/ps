#include <iostream>

using namespace std;

int main() {
    int sum, diff;
    int x, y;

    cin >> sum >> diff;
    x = (sum + diff)/2;
    y = (sum - diff)/2;
    if (diff > sum) cout << -1;
    else if (x + y == sum && x - y == diff) cout << x << ' ' << y;
    else cout << -1;
}