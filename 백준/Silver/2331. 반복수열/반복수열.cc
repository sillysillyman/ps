#include <cmath>
#include <cstdio>
#include <map>

using namespace std;

map<int, int> cnts;

int calc(int x, int n) {
  int res = 0;

  while (x) {
    res += (int)pow((x % 10), n);
    x /= 10;
  }
  return res;
}

int main() {
  bool flag = false;
  int A, P, curr, next;

  scanf("%d%d", &A, &P);
  curr = A;
  while (true) {
    if (flag && cnts.find(curr) == cnts.end()) break;
    ++cnts[curr];
    if (cnts[curr] > 1) {
      flag = true;
      cnts.erase(curr);
    }
    curr = calc(curr, P);
  }
  printf("%zu", cnts.size());
}