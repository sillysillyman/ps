#include <cstdio>
#include <set>

using namespace std;

int main() {
  int L;
  pair<int, int> p;
  set<pair<int, int>> s;
  char S[1001];
  scanf("%d%s", &L, S);
  s.insert(p);
  for (int i = 0; i < L; i++) {
    p.first += S[i] == 'N' ? 1 : S[i] == 'S' ? -1 : 0;
    p.second += S[i] == 'E' ? 1 : S[i] == 'W' ? -1 : 0;
    s.insert(p);
  }
  printf("%ld", s.size());
}