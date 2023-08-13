#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int A, B, C;
    long long res;

    cin >> A >> B >> C;
    res = max(A*((double)B/C), ((double)A/B)*C);
    cout << res;
}