#include <algorithm>
#include <cstdio>

int main() {
  char num[7];

  scanf("%s", num);
  std::sort(num, num + 6, std::greater());
  printf("%s", num);
}