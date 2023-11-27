#include <iostream>

using namespace std;

int network[101][101];

int main() {
  int N, K, A, B;

  cin >> N >> K;
  fill(&network[1][1], &network[N][N + 1], 10000);
  for (int i = 1; i <= N; i++) network[i][i] = 0;
  for (int i = 0; i < K; i++) {
    cin >> A >> B;
    network[A][B] = 1;
    network[B][A] = 1;
  }
  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        network[i][j] = min(network[i][j], network[i][k] + network[k][j]);
        network[j][i] = network[i][j];
      }
    }
  }
  
  int max_dist = 0;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) max_dist = max(max_dist, network[i][j]);
  }
//   cout << '\n';
//   for (int i = 1; i <= N; i++) {
//     for (int j = 1; j <= N; j++) cout << network[i][j] << ' ';
//     cout << '\n';
//   }
//   cout << '\n';
//   cout << max_dist << endl;
  max_dist > 6 ? cout << "Big World!" : cout << "Small World!";
}