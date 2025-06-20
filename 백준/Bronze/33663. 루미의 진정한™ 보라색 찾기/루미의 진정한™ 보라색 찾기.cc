#include <algorithm>
#include <cstdio>

int main() {
  int hl, hh, sl, sh, vl, vh, R, G, B;
  double H, S, V;
  scanf("%d%d%d%d%d%d%d%d%d", &hl, &hh, &sl, &sh, &vl, &vh, &R, &G, &B);

  auto [m, M] = std::minmax({R, G, B});
  V = M;
  S = 255 * (V - m) / V;
  H = V == R ? 60 * (G - B) / (V - m) : V == G ? 120 + 60 * (B - R) / (V - m) : 240 + 60 * (R - G) / (V - m);
  if (H < 0) H += 360;

  printf("Lumi will%slike it.", hl <= H && H <= hh && sl <= S && S <= sh && vl <= V && V <= vh ? " " : " not ");
}