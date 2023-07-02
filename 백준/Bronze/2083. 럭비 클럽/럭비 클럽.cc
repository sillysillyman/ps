#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string name;
    int age, weight;

    while (true) {
        cin >> name >> age >> weight;
        if (name == "#" && age == 0 && weight == 0) break;
        cout << name << ' ';
        if (age > 17 || weight >= 80) cout << "Senior" << endl;
        else cout << "Junior" << endl;
    }
}