#include <iostream>

using namespace std;

int freqs[26];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string line;
  int max_freq = 0;

  while (getline(cin, line)) {
    for (char letter : line) {
      if (letter < 'a' || letter > 'z') continue;
      freqs[letter - 'a']++;
      max_freq = max(max_freq, freqs[letter - 'a']);
    }
  }
  for (int i = 0; i < 26; i++) {
    if (freqs[i] == max_freq) cout << (char)(i + 'a');
  }
}