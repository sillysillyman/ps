#include <algorithm>
#include <cstdio>

int arr[62] = {5,     8,     55,    58,    85,    88,    555,   558,   585,
               588,   855,   858,   885,   888,   5555,  5558,  5585,  5588,
               5855,  5858,  5885,  5888,  8555,  8558,  8585,  8588,  8855,
               8858,  8885,  8888,  55555, 55558, 55585, 55588, 55855, 55858,
               55885, 55888, 58555, 58558, 58585, 58588, 58855, 58858, 58885,
               58888, 85555, 85558, 85585, 85588, 85855, 85858, 85885, 85888,
               88555, 88558, 88585, 88588, 88855, 88858, 88885, 88888};
int A[50], B[50], C[50];
bool flag[90'001];

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

    for (int i = 0; i < 90'001; i++) flag[i] = false;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        for (int k = 0; k < K; k++) flag[A[i] + B[j] + C[k]] = true;

    int cnt = 0;
    for (int i = 0; i < 62; i++)
      if (flag[arr[i]]) ++cnt;
    printf("%d\n", cnt);
  }
}