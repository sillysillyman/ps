#include <iostream>
#include <map>

using namespace std;

map<char, int> tracks;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  char hellobit;
  int N;

  cin >> N;
  while (N--) {
    char track;

    cin >> track;
    tracks[track]++;
  }
  cin >> hellobit;
  cout << tracks[hellobit];
}