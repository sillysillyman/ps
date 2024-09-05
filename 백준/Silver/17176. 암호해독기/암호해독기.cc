#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

char encoded[100'001], decoded[100'001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;

  cin >> N;
  for (int num, i = 0; i < N; i++) {
    cin >> num;
    if (!num)
      encoded[i] = ' ';
    else if (0 < num && num < 27)
      encoded[i] = 'A' + num - 1;
    else
      encoded[i] = 'a' + num - 27;
  }
  encoded[N] = '\0';
  cin.ignore();
  cin.getline(decoded, N + 1);
  sort(encoded, encoded + N);
  sort(decoded, decoded + N);
  cout << (strcmp(encoded, decoded) ? 'n' : 'y');
}