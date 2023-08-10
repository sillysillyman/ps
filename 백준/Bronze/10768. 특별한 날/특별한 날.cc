#include <iostream>

using namespace std;

int main () {
    int month, day;

    cin >> month >> day;
    if (month == 2) {
        if (day == 18) cout << "Special";
        else if (day < 18) cout << "Before";
        else cout << "After";
    } else if (month < 2) cout << "Before";
    else cout << "After";
}