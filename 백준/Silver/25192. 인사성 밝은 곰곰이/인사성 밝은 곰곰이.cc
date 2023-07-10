#include <iostream>
#include <map>

using namespace std;

int main() {
    int N;
    int cnt = 0;
    string line;
    map<string, int> users;


    cin >> N;
    while (N--) {
        cin >> line;
        if (line == "ENTER") users.clear();
        else {
            if (users[line] >= 1) continue;
            else {
                users[line]++;
                cnt++;
            }
        }
    }
    cout << cnt;
}