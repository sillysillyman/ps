#include <map>
#include <string>
#include <vector>

using namespace std;

int convert_time_to_minutes(string& time_str) {
  int hour = stoi(time_str.substr(0, 2));
  int minute = stoi(time_str.substr(3));

  return 60 * hour + minute;
}

int solution(vector<vector<string>> book_time) {
  int answer = 0;
  map<int, int> time_events;

  for (auto& times : book_time) {
    int check_in_time = convert_time_to_minutes(times[0]);
    int check_out_time = convert_time_to_minutes(times[1]) + 10;

    ++time_events[check_in_time];
    --time_events[check_out_time];
  }

  int curr_in_use = 0;

  for (auto& [time_event, cnt] : time_events) {
    curr_in_use += cnt;
    answer = max(answer, curr_in_use);
  }
  return answer;
}