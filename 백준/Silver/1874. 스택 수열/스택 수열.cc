#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    int num, curr = 1;
    bool success = true;
    stack<int> s;
    string ops = "";

    cin >> n;
    while (n--) {
        cin >> num;
        while (curr <= num) {
            s.push(curr);
            ops += '+';
            curr++;
        }
        if (num == s.top()) {
                s.pop();
                ops += '-';
        } else success = false;
    }
    if (!success) cout << "NO";
    else {
        for (char op : ops) {
            cout << op << '\n';
        }
    }
}