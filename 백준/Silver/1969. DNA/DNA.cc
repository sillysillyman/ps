#include <algorithm>
#include <cstdio>

char bases[4] = {'A', 'C', 'G', 'T'};
char dna[51];
char dnas[1'000][51];

int main() {
  int N, M, d = 0;
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) scanf(" %s", dnas[i]);
  for (int j = 0; j < M; j++) {
    int cnts[4] = {};

    for (int i = 0; i < N; i++) {
      if (dnas[i][j] == 'A')
        ++cnts[0];
      else if (dnas[i][j] == 'C')
        ++cnts[1];
      else if (dnas[i][j] == 'G')
        ++cnts[2];
      else
        ++cnts[3];
    }
    int max_idx = std::max_element(cnts, cnts + 4) - cnts;
    for (int k = 0; k < 4; k++) {
      if (k == max_idx) continue;
      d += cnts[k];
    }
    dna[j] = bases[max_idx];
  }
  printf("%s\n%d", dna, d);
}