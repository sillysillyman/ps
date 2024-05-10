#include <algorithm>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

pair<string, string> split(string str, char delimeter) {
  istringstream iss(str);
  string buffer;
  vector<string> res;

  while (getline(iss, buffer, delimeter)) res.push_back(buffer);
  return {res[0], res[1]};
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
  vector<int> answer;
  map<string, int> reported_cnts;
  map<string, vector<string>> report_logs;

  sort(report.begin(), report.end());
  report.erase(unique(report.begin(), report.end()), report.end());
  for (auto& log : report) {
    auto [from, to] = split(log, ' ');

    report_logs[from].push_back(to);
    reported_cnts[to]++;
  }
  answer.resize(id_list.size());
  for (int i = 0; i < id_list.size(); i++) {
    for (string& reported_id : report_logs[id_list[i]]) {
      if (reported_cnts[reported_id] >= k) answer[i]++;
    }
  }
  return answer;
}