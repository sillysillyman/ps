#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, X;
    int cmd;
    stack<int> s;

    cin >> N;
    while (N--) {
        cin >> cmd;
        switch (cmd) {
            case 1:
                cin >> X;
                s.push(X);
                break;
            case 2:
                if (s.empty()) cout << -1 << '\n';
                else {
                    cout << s.top() << '\n';
                    s.pop();
                }
                break;
            case 3:
                cout << s.size() << '\n';
                break;
            case 4:
                if (s.empty()) cout << 1 << '\n';
                else cout << 0 << '\n';
                break;
            case 5:
                if (s.empty()) cout << -1 << '\n';
                else cout << s.top() << '\n';
                break;
        }
    }
}