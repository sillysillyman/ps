#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> split(string str, char delimiter) {
  istringstream iss(str);
  string buffer;
  vector<int> ret;

  while (getline(iss, buffer, delimiter)) ret.push_back(stoi(buffer));
  return ret;
}

string solution(string s) {
  vector<int> arr = split(s, ' ');

  auto minmax_val_ptr = minmax_element(arr.begin(), arr.end());
  return to_string(*minmax_val_ptr.first) + ' ' +
         to_string(*minmax_val_ptr.second);
}