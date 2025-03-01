#include <cstdio>
#include <stack>

using namespace std;

char word[100'001];

int main() {
  int N, cnt = 0;
  scanf("%d", &N);

  while (N--) {
    scanf(" %s", word);

    stack<char> s;
    for (int i = 0; word[i]; i++) {
      if (!s.empty() && s.top() == word[i])
        s.pop();
      else
        s.push(word[i]);
    }

    if (s.empty()) ++cnt;
  }

  printf("%d", cnt);
}