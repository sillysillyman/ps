#include <cstdio>

int main() {
  char c;
  scanf("%c%*s", &c);
  printf(c == 'F' ? "Foundation" : c == 'C' ? "Claves" : c == 'V' ? "Veritas" : "Exploration");
}