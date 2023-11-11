#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, x;

    cin >> n;
    while (n--) {
        cin >> x;
        if (abs(x)%2) cout << x << " is odd\n";
        else cout << x << " is even\n";
    }
}