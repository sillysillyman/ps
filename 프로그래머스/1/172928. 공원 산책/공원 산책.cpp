#include <string>
#include <vector>

using namespace std;

struct Pos {
  int x, y;

  Pos() : x(0), y(0) {}
  Pos(int x, int y) : x(x), y(y) {}
};

bool is_inside(Pos p, vector<string> park) {
  return 0 <= p.x && p.x < park.size() && 0 <= p.y && p.y < park[0].size();
}

vector<int> solution(vector<string> park, vector<string> routes) {
  Pos curr;

  for (int x = 0; x < park.size(); x++) {
    bool is_found_start_point = false;

    for (int y = 0; y < park[x].size(); y++) {
      if (park[x][y] == 'S') {
        curr.x = x;
        curr.y = y;
        is_found_start_point = true;
        break;
      }
    }
    if (is_found_start_point) break;
  }
  for (string route : routes) {
    char dir = route[0];
    int dist = route[2] - '0';
    Pos copied(curr.x, curr.y);

    switch (dir) {
      case 'N':
        if (!is_inside(Pos(curr.x - dist, curr.y), park)) break;
        for (int i = 0; i < dist; i++) {
          if (park[--curr.x][curr.y] == 'X') {
            curr = copied;
            break;
          }
        }
        break;
      case 'S':
        if (!is_inside(Pos(curr.x + dist, curr.y), park)) break;
        for (int i = 0; i < dist; i++) {
          if (park[++curr.x][curr.y] == 'X') {
            curr = copied;
            break;
          }
        }
        break;
      case 'W':
        if (!is_inside(Pos(curr.x, curr.y - dist), park)) break;
        for (int i = 0; i < dist; i++) {
          if (park[curr.x][--curr.y] == 'X') {
            curr = copied;
            break;
          }
        }
        break;
      case 'E':
        if (!is_inside(Pos(curr.x, curr.y + dist), park)) break;
        for (int i = 0; i < dist; i++) {
          if (park[curr.x][++curr.y] == 'X') {
            curr = copied;
            break;
          }
        }
        break;
    }
  }
  return {curr.x, curr.y};
}