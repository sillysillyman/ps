#include <iostream>
#include <vector>

using namespace std;

int N;
string cipher;
vector<string> dict;

int main() {
  cin >> cipher >> N;
  dict.resize(N);
  for (int i = 0; i < N; i++) cin >> dict[i];

  for (int i = 0; i < 26; i++) {
    for (char& c : cipher) c = 'a' + (c - 'a' + 1) % 26;
    for (string& word : dict) {
      if (cipher.find(word) != string::npos) {
        cout << cipher;
        return 0;
      }
    }
  }
}