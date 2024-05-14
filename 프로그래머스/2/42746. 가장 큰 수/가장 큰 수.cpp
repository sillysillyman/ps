#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers) {
  string answer = "";
  vector<string> number_strings;

  for (int number : numbers) number_strings.push_back(to_string(number));
  sort(number_strings.begin(), number_strings.end(),
       [](string& a, string& b) { return a + b > b + a; });
  for (string number_string : number_strings) answer += number_string;
  while (answer.front() == '0' && answer.size() > 1) answer = answer.substr(1);
  return answer;
}