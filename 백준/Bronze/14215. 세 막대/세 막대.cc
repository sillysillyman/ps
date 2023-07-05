#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int triangle[3];

    for (int i = 0; i < 3; i++) cin >> triangle[i];
    sort(triangle, triangle + 3);
    reverse(triangle, triangle + 3);
    if (triangle[0] < triangle[1] + triangle[2]) cout << triangle[0] + triangle[1] + triangle[2];
    else cout << 2*(triangle[1] + triangle[2]) - 1;
}