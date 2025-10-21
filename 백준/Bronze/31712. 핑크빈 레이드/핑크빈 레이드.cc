#include <cstdio>

int main() {
  int CU, CD, CP, DU, DD, DP, H;
  scanf("%d%d%d%d%d%d%d", &CU, &DU, &CD, &DD, &CP, &DP, &H);
  for (int t = 0; t < 5001; t++) {
    if (!(t % CU)) H -= DU;
    if (!(t % CD)) H -= DD;
    if (!(t % CP)) H -= DP;
    if (H < 1) return printf("%d", t), 0;
  }
}