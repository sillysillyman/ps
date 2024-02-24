#include <iostream>
#include <vector>

using namespace std;

int parents[51];
vector<int> know_truth;

int find(int x) {
  if (parents[x] == x) return x;
  return parents[x] = find(parents[x]);
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (x < y)
    parents[y] = x;
  else
    parents[x] = y;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M, people;

  cin >> N >> M;
  for (int i = 1; i <= N; i++) parents[i] = i;
  cin >> people;
  for (int person, i = 0; i < people; i++) {
    cin >> person;
    merge(0, person);
  }

  int cnt = 0;

  for (int first_person, i = 0; i < M; i++) {
    cin >> people;
    cin >> first_person;
    know_truth.push_back(first_person);
    for (int person, j = 1; j < people; j++) {
      cin >> person;
      merge(first_person, person);
    }
  }
  for (int person : know_truth) {
    if (find(person) != 0) cnt++;
  }
  cout << cnt;
}