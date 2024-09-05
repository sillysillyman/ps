#include <iostream>

using namespace std;

int cnts[53];
char decoded[100'001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;

  cin >> N;
  for (int num, i = 0; i < N; i++) {
    cin >> num;
    ++cnts[num];
  }
  cin.ignore();
  cin.getline(decoded, N + 1);
  for (int i = 0; i < N; i++) {
    if (decoded[i] == ' ')
      --cnts[0];
    else if ('A' <= decoded[i] && decoded[i] <= 'Z')
      --cnts[decoded[i] - 'A' + 1];
    else
      --cnts[decoded[i] - 'a' + 27];
  }
  for (int i = 0; i < 53; i++) {
    if (cnts[i]) {
      cout << 'n';
      return 0;
    }
  }
  cout << 'y';
}