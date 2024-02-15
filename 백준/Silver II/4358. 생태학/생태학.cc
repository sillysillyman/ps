#include <iostream>
#include <map>

using namespace std;

map<string, int> trees;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int size = 0;
  string tree;

  while (getline(cin, tree) && ++size) trees[tree]++;
  cout.precision(4);
  cout << fixed;
  for (auto p : trees)
    cout << p.first << " " << (double)p.second / size * 100 << '\n';
}