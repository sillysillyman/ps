#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string str, char delimiter);

struct Date {
  int year, month, day;

  Date(int year, int month, int day) : year(year), month(month), day(day) {}

  Date(const string& raw_date) {
    vector<string> components = split(raw_date, '.');

    year = stoi(components[0]);
    month = stoi(components[1]);
    day = stoi(components[2]);
  }

  bool operator<(const Date& other) const {
    if (year == other.year) {
      if (month == other.month) return day < other.day;
      return month < other.month;
    }
    return year < other.year;
  }

  Date operator+(const Date& other) const {
    Date ret(year, month, day);

    ret.day += other.day;
    if (ret.day > 28) {
      ret.day %= 28;
      ret.month++;
    }
    ret.month += other.month;
    if (ret.month > 12) {
      ret.year += (ret.month - 1) / 12;
      ret.month = (ret.month - 1) % 12 + 1;
    }
    ret.year += other.year;
    return ret;
  }
};

vector<string> split(string str, char delimiter) {
  istringstream iss(str);
  string buffer;
  vector<string> ret;

  while (getline(iss, buffer, delimiter)) ret.push_back(buffer);
  return ret;
}

vector<int> solution(string today, vector<string> terms,
                     vector<string> privacies) {
  Date today_date(today);
  map<string, int> terms_map;
  vector<int> answer;

  for (auto term : terms) {
    vector<string> tmp = split(term, ' ');

    terms_map[tmp[0]] = stoi(tmp[1]);
  }
  for (int i = 0; i < privacies.size(); i++) {
    vector<string> tmp = split(privacies[i], ' ');

    if (Date(tmp[0]) + Date(0, terms_map[tmp[1]] - 1, 27) < today_date)
      answer.push_back(i + 1);
  }
  return answer;
}