#include <iostream>

using namespace std;

int main() {
    int total;
    int N;
    int a, b;

    cin >> total;
    cin >> N;
    while (N--) {
        cin >> a >> b;
        total -= a*b;
    }
    if (!total) cout << "Yes";
    else cout << "No";
}