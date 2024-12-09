#include <iostream>

using namespace std;

int main() {
  string term;

  for (int i = 1; cin >> term && term != "0"; i++) {
    string prev, next;
    do {
      prev.clear();
      next.clear();
      for (int i = 0; i < term.length(); i += 2)
        for (int j = 0; j < term[i] - '0'; j++) prev += term[i + 1];
      if (prev == term) break;

      int cnt = 1;
      char digit = prev[0];
      for (int i = 1; i < prev.length(); i++) {
        if (prev[i] == digit)
          cnt++;
        else {
          next += cnt + '0';
          next += digit;
          digit = prev[i];
          cnt = 1;
        }
      }
      if (cnt) {
        next += cnt + '0';
        next += digit;
      }
      if (next != term) break;
      term = prev;
    } while (!(term.length() & 1));
    cout << "Test " << i << ": " << term << '\n';
  }
}