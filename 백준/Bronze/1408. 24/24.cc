#include <cstdio>

struct Time {
  int hour, minute, second;

  Time(int hour, int minute, int second)
      : hour(hour), minute(minute), second(second) {}

  Time(char str[9]) {
    hour = 10 * (str[0] - '0') + str[1] - '0';
    minute = 10 * (str[3] - '0') + str[4] - '0';
    second = 10 * (str[6] - '0') + str[7] - '0';
  }

  Time operator-(Time& other) {
    int res_hour, res_minute, res_second;

    res_second = second - other.second;
    if (res_second < 0) {
      res_second += 60;
      --minute;
    }
    res_minute = minute - other.minute;
    if (res_minute < 0) {
      res_minute += 60;
      --hour;
    }
    res_hour = hour - other.hour;
    if (res_hour < 0) res_hour += 24;

    return Time(res_hour, res_minute, res_second);
  }

  void to_string(char* str) {
    snprintf(str, 9, "%02d:%02d:%02d", hour, minute, second);
  }
};

int main() {
  char now_str[9], start_str[9], diff_str[9];
  scanf("%s%s", now_str, start_str);

  Time now = Time(now_str);
  Time start = Time(start_str);
  (start - now).to_string(diff_str);
  printf("%s", diff_str);
}