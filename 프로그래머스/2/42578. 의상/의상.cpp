#include <map>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
  int answer = 1;
  map<string, int> cnts;

  for (auto& info : clothes) cnts[info[1]]++;
  for (auto& [type, cnt] : cnts) answer *= cnt + 1;
  return answer - 1;
}