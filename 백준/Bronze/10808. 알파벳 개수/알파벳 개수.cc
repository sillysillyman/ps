#include <iostream>
#include <map>

using namespace std;

int main() {
    string S;
    map<char, int> alphabets;

    for (char i = 'a'; i <= 'z'; i++) alphabets[i] = 0;
    cin >> S;
    for (auto i : S) alphabets[i]++;
    for (auto i : alphabets) cout << i.second << ' ';
}