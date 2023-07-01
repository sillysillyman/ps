#include <iostream>

using namespace std;

int main() {
    int X;
    int sum = 0;
    int num = 1;

    cin >> X;
    while (sum < X) {
        if (sum + num >= X) break;
        sum += num;
        num++;
    }
    if (num%2) cout << num + sum - X + 1 << '/' << X - sum;
    else cout << X - sum << '/' << num + sum - X + 1;
}