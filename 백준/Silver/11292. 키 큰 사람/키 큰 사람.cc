#include <iostream>

using namespace std;

pair<float, string> info[50];

int main() {
  while (true) {
    int N;

    cin >> N;
    if (N == 0) break;

    float max_height = 0;

    for (int i = 0; i < N; i++) {
      float height;
      string name;

      cin >> name >> height;
      max_height = max(max_height, height);
      info[i] = {height, name};
    }
    for (int i = 0; i < N; i++) {
      if (info[i].first == max_height) cout << info[i].second << ' ';
    }
    cout << '\n';
  }
}