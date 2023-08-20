#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string line;

    while (true) {
        getline(cin, line);
        if (line == "END") break;
        reverse(line.begin(), line.end());
        cout << line << '\n';
    }
}