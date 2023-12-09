#include <algorithm>
#include <iostream>

using namespace std;

bool compare(string a, string b) { return a.length() < b.length(); }

int main() {
  int N;
  string words[50];

  cin >> N;
  for (int i = 0; i < N; i++) cin >> words[i];
  sort(words, words + N, compare);

  int cnt = N;

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (words[j].substr(0, words[i].length()) == words[i]) {
        cnt--;
        break;
      }
    }
  }
  cout << cnt;
}