#include <iostream>
#include <sstream>
#include <deque>

using namespace std;

deque<int> split(string str, char delimiter) {
  deque<int> dq;
  istringstream iss(str);
  string buffer;

  while (getline(iss, buffer, delimiter)) dq.push_back(stoi(buffer));
  return dq;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T, n;
  string p;
  string x;

  cin >> T;
  while (T--) {
    bool is_error = false;
    bool is_reversed = false;
    deque<int> dq;

    cin >> p >> n >> x;
    x = x.substr(1, x.length() - 2);
    dq = split(x, ',');
    for (char func : p) {
      if (func == 'R') is_reversed = !is_reversed;
      else if (func == 'D') {
        if (dq.empty()) is_error = true;
        else if (is_reversed) dq.pop_back();
        else dq.pop_front();
      }
    }
    if (is_error) cout << "error" << '\n';
    else {
      cout << '[';
      if (is_reversed) {
        while (!dq.empty()) {
          if (dq.size() == 1) cout << dq.back();
          else cout << dq.back() << ',';
            dq.pop_back();
        }
      } else {
        while (!dq.empty()) {
          if (dq.size() == 1) cout << dq.front();
          else cout << dq.front() << ',';
          dq.pop_front();
        }
      }
      cout << "]\n";
    }
  }
}