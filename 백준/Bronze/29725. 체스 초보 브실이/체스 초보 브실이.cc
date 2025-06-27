#include <cstdio>
#include <map>

int n;
std::map<char, int> m = {
    {'P', 1}, {'p', -1},
    {'N', 3}, {'n', -3},
    {'B', 3}, {'b', -3},
    {'R', 5}, {'r', -5},
    {'Q', 9}, {'q', -9},
    {'K', 0}, {'k', 0}
};

int main() {
  char c;
  for (int i = 0; i < 64; i++) {
    scanf(" %c", &c);
    if (c == '.') continue;
    n += m[c];
  }
  printf("%d", n);
}