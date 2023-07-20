#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string a, const string b) {
    if (a.length() != b.length()) return a.length() < b.length();
    else {
        int sum_a = 0;
        int sum_b = 0;

        for (auto c : a) {
            if (isdigit(c)) sum_a += c - '0';
        }
        for (auto c : b) {
            if (isdigit(c)) sum_b += c - '0';
        }
        if (sum_a != sum_b) return sum_a < sum_b;
        else return a < b;
    }
}

int main() {
    int N;
    string serial;
    vector<string> serials;

    cin >> N;
    while (N--) {
        cin >> serial;
        serials.push_back(serial);
    }
    sort(serials.begin(), serials.end(), cmp);
    for (auto serial : serials) cout << serial << endl;
}