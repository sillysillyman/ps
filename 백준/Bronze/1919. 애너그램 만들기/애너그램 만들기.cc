#include <iostream>
#include <map>

using namespace std;

int main() {
  string word1, word2;
  map<char, int> word_map;
  map<char, int> anagram;

  cin >> word1 >> word2;
  for (char letter : word1) word_map[letter]++;
  for (char letter : word2) anagram[letter]++;
  for (auto i : word_map) {
    if (!anagram[i.first]) anagram[i.first] = i.second;
    else anagram[i.first] = abs(anagram[i.first] - i.second);
  }

  int cnt = 0;

  for (auto i : anagram) cnt += i.second;
  cout << cnt;
}