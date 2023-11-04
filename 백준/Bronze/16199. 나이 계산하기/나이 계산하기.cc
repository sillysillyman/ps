#include <iostream>

using namespace std;

int main() {
    int age;
    int birthday[3];
    int today[3];

    for (int i = 0; i < 3; i++) cin >> birthday[i];
    for (int i = 0; i < 3; i++) cin >> today[i];
    age = today[0] - birthday[0];
    if (today[1] < birthday[1]) age--;
    else if (today[1] == birthday[1] && today[2] < birthday[2]) age--;
    cout << age << '\n';
    age = today[0] - birthday[0] + 1;
    cout << age << '\n';
    age--;
    cout << age;
}