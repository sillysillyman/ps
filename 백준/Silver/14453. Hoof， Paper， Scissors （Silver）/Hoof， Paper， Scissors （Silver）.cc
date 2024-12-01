#include <algorithm>
#include <cstdio>
#include <tuple>

using namespace std;

tuple<int, int, int> arr[100'001];

int main() {
  int N;

  scanf("%d", &N);
  arr[0] = {0, 0, 0};
  for (int i = 1; i <= N; i++) {
    char gesture;

    scanf(" %c", &gesture);
    arr[i] = arr[i - 1];
    if (gesture == 'H')
      ++get<0>(arr[i]);
    else if (gesture == 'P')
      ++get<1>(arr[i]);
    else
      ++get<2>(arr[i]);
  }

  int max_win = max({get<0>(arr[N]), get<1>(arr[N]), get<2>(arr[N])});
  for (int i = 0; i <= N; i++)
    max_win = max({max_win,
                   get<0>(arr[i]) + max(get<1>(arr[N]) - get<1>(arr[i]),
                                        get<2>(arr[N]) - get<2>(arr[i])),
                   get<1>(arr[i]) + max(get<0>(arr[N]) - get<0>(arr[i]),
                                        get<2>(arr[N]) - get<2>(arr[i])),
                   get<2>(arr[i]) + max(get<0>(arr[N]) - get<0>(arr[i]),
                                        get<1>(arr[N]) - get<1>(arr[i]))});
  printf("%d", max_win);
}