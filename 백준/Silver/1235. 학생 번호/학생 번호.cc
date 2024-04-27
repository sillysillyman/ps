#include <iostream>
#include <map>

using namespace std;

string students[1'000];

int main() {
  int N, k = 1;

  cin >> N;
  for (int i = 0; i < N; i++) cin >> students[i];
  while (true) {
    map<string, int> hash;

    for (int i = 0; i < N; i++)
      hash[students[i].substr(students[i].length() - k)]++;
    if (hash.size() == N) break;
    k++;
  }
  cout << k;
}