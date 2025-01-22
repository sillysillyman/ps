#include <cstdio>
#include <map>
#include <vector>

using namespace std;

map<vector<int>, int> m;

int main() {
  int N;
  scanf("%d\n", &N);
  while (N--) {
    char c;
    vector<int> a(26, 0);

    while ((c = getchar()) != '\n') ++a[c - 'a'];
    m[a] = 1;
  }
  printf("%zu", m.size());
}