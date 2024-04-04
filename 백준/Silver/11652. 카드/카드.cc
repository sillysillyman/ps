#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

map<long long, int> cards;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;

  cin >> N;
  for (int i = 0; i < N; i++) {
    long long card;

    cin >> card;
    cards[card]++;
  }
  cout << (*max_element(cards.begin(), cards.end(),
                        [](const auto& a, const auto& b) {
                          return a.second < b.second;
                        }))
              .first;
}