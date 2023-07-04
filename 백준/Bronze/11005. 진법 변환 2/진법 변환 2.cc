#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, B;
    string num;

    cin >> N >> B;
    while (N) {
        if (N%B < 10) num += to_string(N%B);
        else num += (N%B - 10) + 'A';
        N /= B;
    }
    reverse(num.begin(), num.end());
    cout << num;
}