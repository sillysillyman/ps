#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> split(string str, char delimiter) {
  istringstream iss(str);
  string buffer;
  vector<int> splitted;

  while (getline(iss, buffer, delimiter)) splitted.push_back(stoi(buffer));
  return splitted;
}

vector<int> change(vector<int> v) {
  int len = v.size();
  vector<int> ret(len - 1);

  for (int i = 0; i < len - 1; i++) ret[i] = v[i + 1] - v[i];
  return ret;
}

int main() {
  int N, K;
  string sequence;
  vector<int> A;

  cin >> N >> K;
  cin >> sequence;
  A = split(sequence, ',');
  for (int i = 0; i < K; i++) A = change(A);
  for (int i = 0; i < A.size(); i++) {
    if (i == A.size() - 1)
      cout << A[i];
    else
      cout << A[i] << ',';
  }
}