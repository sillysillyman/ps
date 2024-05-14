#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

bool is_prime(int num) {
  if (num < 2) return false;
  for (int i = 2; i * i <= num; i++) {
    if (!(num % i)) return false;
  }
  return true;
}

int solution(string numbers) {
  map<int, int> cnts;

  sort(numbers.begin(), numbers.end());
  do {
    string number = "";

    for (char digit : numbers) {
      number += digit;
      if (is_prime(stoi(number))) cnts[stoi(number)] = 1;
    }
  } while (next_permutation(numbers.begin(), numbers.end()));
  return cnts.size();
}