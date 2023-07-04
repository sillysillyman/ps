#include <iostream>

using namespace std;

bool is_triangle(int a, int b, int c) {
    return a + b > c && a + c > b && b + c > a;
}

int main() {
    int a, b, c;
    
    while (true) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) break;
        if (!is_triangle(a, b, c)) cout << "Invalid" << endl;
        else if (a == b && b == c && c == a) cout << "Equilateral" << endl;
        else if (a == b || b == c || c == a) cout << "Isosceles" << endl;
        else cout << "Scalene" << endl;
    }
}