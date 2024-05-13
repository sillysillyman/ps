#include <cmath>
#include <map>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

vector<string> split(string str, char delimiter);

struct Time {
  int hour, minute;

  bool operator<(const Time& other) const {
    if (hour == other.hour) return minute < other.minute;
    return hour < other.hour;
  }

  Time() : hour(-1), minute(-1) {}

  Time(int hour, int minute) : hour(hour), minute(minute) {}

  Time(string time) {
    vector<string> split_time = split(time, ':');

    hour = stoi(split_time[0]);
    minute = stoi(split_time[1]);
  }

  int to_minute() { return 60 * hour + minute; }
};

vector<string> split(string str, char delimiter) {
  istringstream iss(str);
  string buffer;
  vector<string> ret;

  while (getline(iss, buffer, delimiter)) ret.push_back(buffer);
  return ret;
}

vector<int> solution(vector<int> fees, vector<string> records) {
  vector<int> answer;
  map<int, tuple<Time, Time, int>> info;

  for (string record : records) {
    vector<string> split_record = split(record, ' ');
    int id = stoi(split_record[1]);
    Time time = Time(split_record[0]);

    if (split_record[2] == "IN")
      get<0>(info[id]) = time;
    else if (split_record[2] == "OUT") {
      get<1>(info[id]) = time;
      get<2>(info[id]) += time.to_minute() - get<0>(info[id]).to_minute();
    }
  }
  for (auto& [k, v] : info) {
    if (get<1>(v) < get<0>(v)) {
      get<1>(v) = Time("23:59");
      get<2>(v) += get<1>(v).to_minute() - get<0>(v).to_minute();
    }
    if (get<2>(v) <= fees[0])
      answer.push_back(fees[1]);
    else
      answer.push_back(
          fees[1] +
          fees[3] * ((int)ceil((double)(get<2>(v) - fees[0]) / fees[2])));
  }
  return answer;
}