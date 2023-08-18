#include <iostream>
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    char cmd, alpha;
    int M;
    string S;
    list<char> l;

    cin >> S >> M;
    for (auto c : S) l.push_back(c);
    auto cursor = l.end();
    while (M--) {
        cin >> cmd;
        if (cmd == 'L') {
            if (cursor == l.begin()) continue;
            else cursor--;
        } else if (cmd == 'D') {
            if (cursor == l.end()) continue;
            else cursor++;
        } else if (cmd == 'B') {
            if (cursor == l.begin()) continue;
            else {
                cursor--;
                // l.erase(cursor);
                cursor = l.erase(cursor);
            }
        } else if (cmd == 'P') {
            cin >> alpha;
            l.insert(cursor, alpha);
        }
        // cout << "l: ";
        // for (auto c : l) cout << c;
        // cout << '\n';
    }
    for (auto c : l) cout << c;
    // for (auto c : l) cout << c;
    // cout << "l: ";
    // for (auto c : l) cout << c;
    // cout << '\n';
    // cursor--;
    // l.erase(cursor);
    // cout << "l: ";
    // for (auto c : l) cout << c;
    // cout << '\n';
    // cursor--;
    // l.erase(cursor);
    // cout << "l: ";
    // for (auto c : l) cout << c;
    // cout << '\n';
    // // cursor--;
    // l.erase(cursor);
    // cout << "l: ";
    // for (auto c : l) cout << c;
    // cout << '\n';
}