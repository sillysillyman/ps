#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    int T;
    string name;
    map<string, int> never_seen_and_heard_cnt;
    vector<string> never_seen_and_heard;

    cin >> N >> M;
    T = N + M;
    while(T--) {
        cin >> name;
        never_seen_and_heard_cnt[name]++;
        if (never_seen_and_heard_cnt[name] > 1) never_seen_and_heard.push_back(name);
    }
    sort(never_seen_and_heard.begin(), never_seen_and_heard.end());
    cout << never_seen_and_heard.size() << '\n';
    for (string name : never_seen_and_heard) cout << name << '\n';
}