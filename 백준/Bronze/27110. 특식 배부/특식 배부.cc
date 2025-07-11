#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
  int N, A, B, C;
  scanf("%d%d%d%d", &N, &A, &B, &C);
  printf("%d", min(N, A) + min(N, B) + min(N, C));
}