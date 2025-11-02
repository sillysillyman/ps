#include <cstdio>

int main() {
  char c;
  scanf("%c", &c);
  printf(c == 'M' ? "MatKor" : c == 'W' ? "WiCys" : c == 'C' ? "CyKor" : c == 'A' ? "AlKor" : "$clear");
}