#include <cstdio>
#include <utility>

int main() {
  std::pair p = {0, 1};
  for (int t, i = 0; i < 10; i++) {
    scanf("%d", &t);
    if (t == 1) p = {p.second , -p.first};
    else if (t == 2) p = {-p.first, -p.second};
    else p = {-p.second, p.first};
  }
  printf("%c", p.second == 1 ? 'N' : p.first == 1 ? 'E' : p.first == -1 ? 'W' : 'S');
}