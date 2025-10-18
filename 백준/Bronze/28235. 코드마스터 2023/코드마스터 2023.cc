#include <cstdio>

int main() {
  char s[10];
  scanf("%s", s);
  printf(s[0] == 'S' ? "HIGHSCHOOL" : s[0] == 'C' ? "MASTER" : s[0] == '2' ? "0611" : "CONTEST");
}