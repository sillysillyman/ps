#include <iostream>

using namespace std;

int cycles;
bool visited[1001];
int permutation[1001];

void find_cycle(int src_idx, int idx) {
  if (visited[idx]) return;
  visited[idx] = true;
  if (permutation[idx] == src_idx) {
    cycles++;
    return;
  }
  find_cycle(src_idx, permutation[idx]);
}

int main() {
  int T, N;

  cin >> T;
  while (T--) {
    cycles = 0;    
    cin >> N;
    fill(visited + 1, visited + N + 1, false);
    for (int i = 1; i <= N; i++) cin >> permutation[i];
    for (int i = 1; i <= N; i++) find_cycle(i, i);
    cout << cycles << '\n';
  }
}
// 1 2 3 4 5 6 7 8  9 10
// 2 1 3 4 5 6 7 9 10  8
