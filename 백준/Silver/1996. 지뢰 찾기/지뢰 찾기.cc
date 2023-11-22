#include <iostream>

using namespace std;

int N;
char map[1000][1000];

char sweep(int i, int j) {
  if (map[i][j] != '.') return '*';

  int cnt = 0;

  if (i == 0) {
    if (j == 0) {
      if (isdigit(map[i][j + 1])) cnt += map[i][j + 1] - '0';
      if (isdigit(map[i + 1][j])) cnt += map[i + 1][j] - '0';
      if (isdigit(map[i + 1][j + 1])) cnt += map[i + 1][j + 1] - '0';
    } else if (j == N - 1) {
      if (isdigit(map[i][j - 1])) cnt += map[i][j - 1] - '0';
      if (isdigit(map[i + 1][j - 1])) cnt += map[i + 1][j - 1] - '0';
      if (isdigit(map[i + 1][j])) cnt += map[i + 1][j] - '0';
    } else {
      if (isdigit(map[i][j - 1])) cnt += map[i][j - 1] - '0';
      if (isdigit(map[i][j + 1])) cnt += map[i][j + 1] - '0';
      if (isdigit(map[i + 1][j - 1])) cnt += map[i + 1][j - 1] - '0';
      if (isdigit(map[i + 1][j])) cnt += map[i + 1][j] - '0';
      if (isdigit(map[i + 1][j + 1])) cnt += map[i + 1][j + 1] - '0';
    }
  } else if (i == N - 1) {
    if (j == 0) {
      if (isdigit(map[i - 1][j])) cnt += map[i - 1][j] - '0';
      if (isdigit(map[i - 1][j + 1])) cnt += map[i - 1][j + 1] - '0';
      if (isdigit(map[i][j + 1])) cnt += map[i][j + 1] - '0';
    } else if (j == N - 1) {
      if (isdigit(map[i - 1][j - 1])) cnt += map[i - 1][j - 1] - '0';
      if (isdigit(map[i - 1][j])) cnt += map[i - 1][j] - '0';
      if (isdigit(map[i][j - 1])) cnt += map[i][j - 1] - '0';
    } else {
      if (isdigit(map[i - 1][j - 1])) cnt += map[i - 1][j - 1] - '0';
      if (isdigit(map[i - 1][j])) cnt += map[i - 1][j] - '0';
      if (isdigit(map[i - 1][j + 1])) cnt += map[i - 1][j + 1] - '0';
      if (isdigit(map[i][j - 1])) cnt += map[i][j - 1] - '0';
      if (isdigit(map[i][j + 1])) cnt += map[i][j + 1] - '0';
    }
  } else if (j == 0) {
    if (isdigit(map[i - 1][j])) cnt += map[i - 1][j] - '0';
    if (isdigit(map[i - 1][j + 1])) cnt += map[i - 1][j + 1] - '0';
    if (isdigit(map[i][j + 1])) cnt += map[i][j + 1] - '0';
    if (isdigit(map[i + 1][j])) cnt += map[i + 1][j] - '0';
    if (isdigit(map[i + 1][j + 1])) cnt += map[i + 1][j + 1] - '0';
  } else if (j == N - 1) {
    if (isdigit(map[i - 1][j - 1])) cnt += map[i - 1][j - 1] - '0';
    if (isdigit(map[i - 1][j])) cnt += map[i - 1][j] - '0';
    if (isdigit(map[i][j - 1])) cnt += map[i][j - 1] - '0';
    if (isdigit(map[i + 1][j - 1])) cnt += map[i + 1][j - 1] - '0';
    if (isdigit(map[i + 1][j])) cnt += map[i + 1][j] - '0';
  } else {
    if (isdigit(map[i - 1][j - 1])) cnt += map[i - 1][j - 1] - '0';
    if (isdigit(map[i - 1][j])) cnt += map[i - 1][j] - '0';
    if (isdigit(map[i - 1][j + 1])) cnt += map[i - 1][j + 1] - '0';
    if (isdigit(map[i][j - 1])) cnt += map[i][j - 1] - '0';
    if (isdigit(map[i][j + 1])) cnt += map[i][j + 1] - '0';
    if (isdigit(map[i + 1][j - 1])) cnt += map[i + 1][j - 1] - '0';
    if (isdigit(map[i + 1][j])) cnt += map[i + 1][j] - '0';
    if (isdigit(map[i + 1][j + 1])) cnt += map[i + 1][j + 1] - '0';
  }
  return (cnt < 10 ? cnt + '0' : 'M');
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) cin >> map[i][j];
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) cout << sweep(i, j);
    cout << '\n';
  }
}