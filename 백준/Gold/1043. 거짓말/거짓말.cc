#include <cstdio>
#include <vector>

using namespace std;

int p[51];
vector<int> know_truth;

int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }

void unite(int x, int y) { p[find(x)] = find(y); }

int main() {
  int N, M, people, cnt = 0;

  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++) p[i] = i;
  scanf("%d", &people);
  for (int person, i = 0; i < people; i++) {
    scanf("%d", &person);
    unite(0, person);
  }
  for (int first_person, i = 0; i < M; i++) {
    scanf("%d", &people);
    scanf("%d", &first_person);
    know_truth.push_back(first_person);
    for (int person, j = 1; j < people; j++) {
      scanf("%d", &person);
      unite(first_person, person);
    }
  }
  for (int person : know_truth)
    if (find(person) != find(0)) ++cnt;
  printf("%d", cnt);
}