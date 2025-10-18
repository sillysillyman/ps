#include <cstdio>
#include <cstring>

int main() {
  char s[10];
  scanf("%s", s);
  printf(!strcmp(s, "SONGDO") ? "HIGHSCHOOL" : !strcmp(s, "CODE") ? "MASTER" : !strcmp(s, "2023") ? "0611" : "CONTEST");
}