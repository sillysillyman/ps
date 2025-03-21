#include <cctype>
#include <cstdio>
#include <cstring>

int main() {
  char A[101], B[101];
  scanf("%s %s", A, B);
  if (!strcmp(A, "null")) {
    for (int i = 0; i < 2; i++) printf("NullPointerException\n");
    return 0;
  }
  if (!strcmp(B, "null")) {
    for (int i = 0; i < 2; i++) printf("false\n");
    return 0;
  }
  printf("%s\n", strcmp(A, B) ? "false" : "true");
  for (int i = 0; A[i]; i++) A[i] = tolower(A[i]);
  for (int i = 0; B[i]; i++) B[i] = tolower(B[i]);
  printf("%s\n", strcmp(A, B) ? "false" : "true");
}