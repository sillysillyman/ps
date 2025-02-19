#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<string, vector<string>> m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  while (N--) {
    string mentor, mentee;
    cin >> mentor >> mentee;
    m[mentor].push_back(mentee);
  }

  for (auto& [mentor, mentees] : m) {
    sort(mentees.begin(), mentees.end(), greater());
    for (auto& mentee : mentees) cout << mentor << " " << mentee << "\n";
  }
}