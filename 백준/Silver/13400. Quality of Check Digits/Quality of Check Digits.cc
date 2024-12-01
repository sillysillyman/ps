#include <algorithm>
#include <cstdio>

int t[10][10];

int calc(int n) {
  return t[t[t[t[0][n / 1000]][n / 100 % 10]][n / 10 % 10]][n % 10];
}

int check(char id[5]) {
  return t[t[t[t[t[0][id[0] - '0']][id[1] - '0']][id[2] - '0']][id[3] - '0']]
          [id[4] - '0'];
}

int main() {
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++) scanf("%d", &t[i][j]);

  int cnt = 0;
  for (int n = 0; n < 10'000; n++) {
    bool flag = false;
    char id[5];

    id[0] = n / 1000 + '0';
    id[1] = n / 100 % 10 + '0';
    id[2] = n / 10 % 10 + '0';
    id[3] = n % 10 + '0';
    id[4] = calc(n) + '0';

    for (int i = 0; i < 5; i++) {
      char digit = id[i];

      for (int j = 0; j < 10; j++) {
        id[i] = j + '0';
        if (id[i] != digit && !check(id)) {
          flag = true;
          break;
        }
      }
      id[i] = digit;
      if (flag) break;
    }

    if (!flag) {
      for (int i = 0; i < 4; i++) {
        if (id[i] == id[i + 1]) continue;
        std::swap(id[i], id[i + 1]);
        if (!check(id)) {
          flag = true;
          break;
        }
        std::swap(id[i], id[i + 1]);
      }
    }

    if (flag) ++cnt;
  }
  printf("%d", cnt);
}