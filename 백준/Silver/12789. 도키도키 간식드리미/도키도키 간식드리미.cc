#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
    int N, num;
    queue<int> q;
    stack<int> s;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        q.push(num);
    }

    int order = 1;

    while (!q.empty()) {
        while (!s.empty()) {
            if (s.top() == order) {
                s.pop();
                order++;
            } else break;
        }
        if (q.front() == order) {
            q.pop();
            order++;
        }
        else {
            s.push(q.front());;
            q.pop();
        }
    }
    while (!s.empty()) {
            if (s.top() == order) {
                s.pop();
                order++;
            } else break;
        }
    if (s.empty()) cout << "Nice";
    else cout << "Sad";
}