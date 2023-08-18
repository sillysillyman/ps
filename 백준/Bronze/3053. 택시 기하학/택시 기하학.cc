#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES

using namespace std;

int main() {
    int R;
    
    cin >> R;
    cout << fixed;
    cout.precision(6);
    cout << (double)M_PI*R*R << '\n';
    cout << (double)2*R*R;
}