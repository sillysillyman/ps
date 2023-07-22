#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    int decomposition_sum;
    bool success = false;

    cin >> N;
    for (int i = 1; i <= 1000000; i++) {
        string n = to_string(i);
        
        decomposition_sum = i;
        for (char unit : n) {
            decomposition_sum += (unit - '0');
        }
        if (decomposition_sum == N) {
            cout << i;
            success = true;
            break;
        }
    }
    if (!success) cout << 0;
}