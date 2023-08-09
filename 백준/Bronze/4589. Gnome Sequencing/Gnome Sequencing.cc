#include <iostream>

using namespace std;

int main() {
    int N;
    int x, y, z;

    cin >> N;
    cout << "Gnomes:\n";
    while (N--) {
        cin >> x >> y >> z;
        if ((x > y && y > z) || (x < y && y < z)) cout << "Ordered\n";
        else cout << "Unordered\n";
    }
}