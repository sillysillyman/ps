#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    string name, state;
    map<string, int, greater<>> logs;

    cin >> n;
    while (n--) {
        cin >> name >> state;
        if (state == "enter") logs[name]++;
        else if (state == "leave") logs[name]--;
    }
    for (auto log : logs) {
        if (log.second > 0) cout << log.first << '\n';
    }
}