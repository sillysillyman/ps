#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N, h;
  vector<int> v;
  cin >> N;
  while (N--) {
    cin >> h;
    while (!v.empty() && v.back() <= h) v.pop_back();
    v.push_back(h);
  }
  cout << v.size();
}