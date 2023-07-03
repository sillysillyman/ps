#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int vowel_cnt;
  string sentence;
  char vowels[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
  
  while (1) {
    vowel_cnt = 0;
    getline(cin, sentence);
    if (sentence == "#") break;
    for (char letter : sentence) {
      for (char vowel : vowels) {
        if (letter == vowel) vowel_cnt++;
      }
    }
    cout << vowel_cnt << '\n';
  }
}