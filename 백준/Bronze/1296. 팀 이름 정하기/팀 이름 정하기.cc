#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  string name, team_name_candidate, team_name;
  int N, probability = 0;

  cin >> name >> N;
  while (N--) {
    cin >> team_name_candidate;

    map<char, int> cnt;

    for (char letter : name) cnt[letter]++;
    for (char letter : team_name_candidate) cnt[letter]++;
    if (int new_probability = ((cnt['L'] + cnt['O']) * (cnt['L'] + cnt['V']) *
                               (cnt['L'] + cnt['E']) * (cnt['O'] + cnt['V']) *
                               (cnt['O'] + cnt['E']) * (cnt['V'] + cnt['E'])) %
                              100;
        new_probability >= probability) {
      if (new_probability == probability) {
        if (team_name.empty())
          team_name = team_name_candidate;
        else
          team_name = (team_name < team_name_candidate ? team_name
                                                       : team_name_candidate);
      } else
        team_name = team_name_candidate;
      probability = new_probability;
    }
  }
  cout << team_name;
}