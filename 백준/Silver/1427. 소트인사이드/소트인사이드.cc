#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string N;
    vector<char> num;

    cin >> N;
    for (char c : N) {
        num.push_back(c);
    }
    sort(num.begin(), num.end(), greater<>());
    for (char c : num) {
        cout << c;
    }
}