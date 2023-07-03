#include <iostream>
#include <stack>

using namespace std;

int main() {
    int min = 0;
    string expr;
    string num = "";
    stack<int> nums;
    bool is_minus = false;

    cin >> expr;
    for (char letter : expr) {
        if (letter == '+' || letter == '-') {
            if (is_minus) nums.push(-stoi(num));
            else nums.push(stoi(num));
            num = "";
            if (letter == '-') is_minus = true;
        } else num += to_string(letter - '0');
    }
    if (is_minus) nums.push(-stoi(num));
    else nums.push(stoi(num));
    while (!nums.empty()) {
        min += nums.top();
        nums.pop();
    }
    cout << min;
}