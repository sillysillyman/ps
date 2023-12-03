#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compare(string a, string b) {
  for (int i = 0; i < a.length(); i++) a[i] = tolower(a[i]);
  for (int i = 0; i < b.length(); i++) b[i] = tolower(b[i]);
  return a < b;
}

int main() {
  int n;

  while (true) {
    cin >> n;
    if (n == 0) break;

    vector<string> words(n);

    for (int i = 0; i < n; i++) cin >> words[i];
    sort(words.begin(), words.end(), compare);
    cout << words[0] << '\n';
  }
}