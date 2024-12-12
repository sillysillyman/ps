#include <cstdio>

const char *num_to_str[] = {
    "o\' clock",   "one",        "two",          "three",        "four",
    "five",        "six",        "seven",        "eight",        "nine",
    "ten",         "eleven",     "twelve",       "thirteen",     "fourteen",
    "quarter",     "sixteen",    "seventeen",    "eighteen",     "nineteen",
    "twenty",      "twenty one", "twenty two",   "twenty three", "twenty four",
    "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine",
    "half"};

int main() {
  int h, m;

  scanf("%d%d", &h, &m);
  if (!m)
    printf("%s %s", num_to_str[h], num_to_str[m]);
  else if (m <= 30) {
    if (m == 15 || m == 30)
      printf("%s past %s", num_to_str[m], num_to_str[h]);
    else
      printf("%s %s past %s", num_to_str[m], (m == 1 ? "minute" : "minutes"),
             num_to_str[h]);
  } else {
    h = h % 12 + 1;
    m = 60 - m;
    if (m == 15)
      printf("%s to %s", num_to_str[m], num_to_str[h]);
    else
      printf("%s %s to %s", num_to_str[m], (m == 1 ? "minute" : "minutes"),
             num_to_str[h]);
  }
}