#include <iostream>

using namespace std;

int main() {
    int N;

    cin >> N;
    if (N == 1) cout << 1;
    else {
        int sum = 1;
        int layer = 1;

        while (!((N > sum) && (N <= sum + 6*layer))) {
            sum += 6*layer;
            layer++;
        }
        cout << layer + 1;
    }
    return 0;
}