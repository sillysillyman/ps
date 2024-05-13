#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string str, char delimiter) {
  istringstream iss(str);
  string buffer;
  vector<string> ret;

  while (getline(iss, buffer, delimiter)) {
    if (!buffer.empty()) ret.push_back(buffer);
  }
  return ret;
}

bool is_prime(long long n) {
  if (n < 2) return false;
  for (long long i = 2; i * i <= n; i++) {
    if (!(n % i)) return false;
  }
  return true;
}

int solution(int n, int k) {
  int answer = 0;
  string k_based = "";

  while (n) {
    k_based = to_string(n % k) + k_based;
    n /= k;
  }

  vector<string> numbers = split(k_based, '0');

  for (string num : numbers) {
    if (is_prime(stoll(num))) ++answer;
  }
  return answer;
}