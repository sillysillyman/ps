#include <iostream>
#include <algorithm>

using namespace std;

bool is_right_triangle(int a, int b, int c) {
    if (!(a < b && b < c)) return false;
    return c*c == a*a + b*b;
}

int main() {
    int n;
    int sides[3];

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> sides[0] >> sides[1] >> sides[2];
        sort(sides, sides + 3);
        cout << "Scenario #" << i << ":\n";
        if (is_right_triangle(sides[0], sides[1], sides[2])) cout << "yes\n";
        else cout << "no\n";
        cout << '\n';
    }
}