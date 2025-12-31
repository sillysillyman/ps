#include <cstdio>
#include <cstring>

int main() {
  char S[9];
  scanf("%s", S);
  printf(!strcmp(S, ";lkjfdsa") ? "reverse" : !strcmp(S, "asdfjkl;") ? "stairs" : !strcmp(S, "asdf;lkj") || !strcmp(S, ";lkjasdf") ? "out-in" : !strcmp(S, "fdsajkl;") || !strcmp(S, "jkl;fdsa") ? "in-out" : "molu");
}