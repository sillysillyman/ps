#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;

  while (cin >> N) {
    string flights;
    set<string> category;

    while (N--) {
      cin >> flights;
      sort(flights.begin(), flights.end());
      flights.erase(unique(flights.begin(), flights.end()), flights.end());
      category.insert(flights);
    }
    cout << category.size() << '\n';
  }
}