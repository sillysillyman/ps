#include <cstdio>

int main() {
  int N;
  char s[23];
  scanf("%d", &N);
  while (N--) {
    scanf("%s", s);
    puts(s[0] == 'A' && s[1] == 'l' ? "204" : s[0] == 'D' ? "207" : s[0] == 'C' ? "B101" : s[0] == 'N' 
? "303" : s[0] == 'S' ? "501" : s[0] == 'T' ? "105" : "302");
  }
}