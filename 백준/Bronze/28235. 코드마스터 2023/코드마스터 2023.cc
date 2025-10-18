#include <cstdio>

int main() {
  char s[10];
  scanf("%s", s);
  printf(*s == 'S' ? "HIGHSCHOOL" : *s == 'C' ? "MASTER" : *s == '2' ? "0611" : "CONTEST");
}