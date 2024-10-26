#include <cstdio>

char A[100'001];
bool B[26];

int main() {
  char ch;

  scanf("%s", A);
  while (~scanf(" %c", &ch))
    if (ch < 'a') B[ch - 'A'] = true;
  for (int i = 0; A[i]; i++)
    if (A[i] < 'a' && B[A[i] - 'A']) A[i] += 32;
  printf("%s", A);
}