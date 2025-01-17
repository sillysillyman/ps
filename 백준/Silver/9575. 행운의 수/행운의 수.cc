#include <cstdio>
#include <map>

int A[50], B[50], C[50];

bool is_lucky_number(int num) {
  while (num) {
    if (int digit = num % 10; digit != 5 && digit != 8) return false;
    num /= 10;
  }
  return true;
}

int main() {
  int T;
  scanf("%d", &T);

  while (T--) {
    int N, M, K;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    scanf("%d", &M);
    for (int i = 0; i < M; i++) scanf("%d", &B[i]);
    scanf("%d", &K);
    for (int i = 0; i < K; i++) scanf("%d", &C[i]);

    std::map<int, int> cnts;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        for (int k = 0; k < K; k++)
          if (int num = A[i] + B[j] + C[k]; is_lucky_number(num)) ++cnts[num];

    printf("%zu\n", cnts.size());
  }
}