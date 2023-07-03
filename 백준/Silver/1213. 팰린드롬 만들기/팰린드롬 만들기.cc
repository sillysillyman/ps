#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> letters;

bool is_able_to_be_palindrome() {
    int odd_cnt = 0;

    for (auto letter : letters) {
        if (letter.second%2) odd_cnt++;
    }
    if (odd_cnt > 1) return false;
    else return true;
}

string make_palindrome() {
    string prefix = "";
    string mid = "";
    string suffix = "";

    for (auto letter : letters) {
        if (letter.second%2) {
            for (int i = 0; i < letter.second; i++) mid += letter.first;
        } else {
            for (int i = 0; i < letter.second/2; i++) prefix += letter.first;
        }
    }
    if (!mid.empty()) {
        for (int i = 0; i < prefix.length(); i++) {
            if (prefix[i] > mid[0]) {
                prefix = prefix.substr(0, i) + mid.substr(0, mid.length()/2) + prefix.substr(i, prefix.length() - i);
                mid = mid[0];
                break;
            }
        }
    }
    for (int i = prefix.length() - 1; i >= 0; i--) suffix += prefix[i];
    if (prefix.empty()) return mid;
    else return prefix + mid + suffix;
}

int main() {
    string name;

    cin >> name;
    for (char letter : name) letters[letter]++;
    if (!is_able_to_be_palindrome()) {
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    cout << make_palindrome();
}