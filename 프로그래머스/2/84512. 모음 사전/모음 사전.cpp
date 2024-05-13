#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(string word) {
  int answer = 0;
  vector<string> words;
  queue<string> queue;

  queue.push("A");
  queue.push("E");
  queue.push("I");
  queue.push("O");
  queue.push("U");
  while (!queue.empty()) {
    string word = queue.front();

    words.push_back(word);
    queue.pop();
    if (word.size() < 5) {
      queue.push(word + "A");
      queue.push(word + "E");
      queue.push(word + "I");
      queue.push(word + "O");
      queue.push(word + "U");
    }
  }
  sort(words.begin(), words.end());
  return lower_bound(words.begin(), words.end(), word) - words.begin() + 1;
}