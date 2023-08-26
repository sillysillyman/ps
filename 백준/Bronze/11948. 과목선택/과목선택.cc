#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int sum = 0;
    int sciences[4];
    int humanities[2];

    for (int i = 0; i < 4; i++) {
        cin >> sciences[i];
        sum += sciences[i];
    }
    for (int i = 0; i < 2; i++) {
        cin >> humanities[i];
        sum += humanities[i];
    }
    sum -= *min_element(sciences, sciences + 4) + *min_element(humanities, humanities + 2);
    cout << sum;
}