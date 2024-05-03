#include <iostream>

using namespace std;

int main() {
    bool asc_success = false;
    bool desc_success = false;
    int scale[8] = {};

    for (int i = 0; i < 8; i++) {
        cin >> scale[i];
    }
    for (int i = 0; i < 7; i++) {
        if (scale[i] - scale[i + 1] == -1) {
            asc_success = true;
            if (desc_success) break;
        }
        else if (scale[i] - scale[i + 1] == 1) {
            desc_success = true;
            if (asc_success) break;
        }
        else {
            asc_success = false;
            desc_success = false;
            break;
        }
    }
    if (asc_success && desc_success) cout << "mixed";
    else if (asc_success) cout << "ascending";
    else if (desc_success) cout << "descending";
    else cout << "mixed";
}