#include <iostream>
#include <queue>
#include <map>

using namespace std;

enum Cmds {PUSH, POP, SIZE, EMPTY, FRONT, BACK};
map<string, int> cmds = {{"push", PUSH},
                        {"pop", POP},
                        {"size", SIZE},
                        {"empty", EMPTY},
                        {"front", FRONT},
                        {"back", BACK}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int num;
    string cmd;
    queue<int> q;

    cin >> N;
    while (N--) {
        cin >> cmd;
        switch (cmds[cmd]) {
            case PUSH:
                cin >> num;
                q.push(num);
                break;
            case POP:
                if (q.empty()) {
                    cout << -1 << '\n';
                    break;
                } else {
                    num = q.front();
                    q.pop();
                    cout << num << '\n';
                }
                break;
            case SIZE:
                cout << q.size() << '\n';
                break;
            case EMPTY:
                cout << (q.empty() ? 1 : 0) << '\n';
                break;
            case FRONT:
                cout << (q.empty() ? -1 : q.front()) << '\n';
                break;
            case BACK:
                cout << (q.empty() ? -1 : q.back()) << '\n';
                break;
        }
    }
}