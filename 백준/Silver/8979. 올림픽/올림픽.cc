#include <algorithm>
#include <cstdio>

using namespace std;

struct Medal {
  int id, rank, gold, silver, bronze;

  bool operator>(const Medal& other) const {
    return gold == other.gold ? (silver == other.silver ? bronze > other.bronze
                                                        : silver > other.silver)
                              : gold > other.gold;
  }

  bool operator==(const Medal& other) const {
    return gold == other.gold && silver == other.silver &&
           bronze == other.bronze;
  }
};

Medal medals[1'001];

int main() {
  int N, K;

  scanf("%d%d", &N, &K);
  for (int i = 0; i < N; i++)
    scanf("%d%d%d%d", &medals[i].id, &medals[i].gold, &medals[i].silver,
          &medals[i].bronze);
  sort(medals, medals + N, greater());
  medals[0].rank = 1;
  for (int gap = 1, i = 1; i < N; i++) {
    if (medals[i] == medals[i - 1]) {
      medals[i].rank = medals[i - 1].rank;
      ++gap;
    } else {
      medals[i].rank = medals[i - 1].rank + gap;
      gap = 1;
    }
  }
  for (int i = 0; i < N; i++) {
    if (medals[i].id == K) {
      printf("%d", medals[i].rank);
      break;
    }
  }
}