#include <cstdio>
#include <cstring>

int main() {
  char A[21], B[21];
  scanf("%s%s", A, B);
  printf(strcmp(A, B) ? "1550" : "0");
}