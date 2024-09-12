#include <algorithm>
#include <cstdio>

using namespace std;

int freq[1'001];

int main() {
  int N;

  scanf("%d", &N);
  while (N--) {
    int n;

    scanf("%d", &n);
    ++freq[n];
  }
  printf("%d", *max_element(freq + 1, freq + 1'001));
}