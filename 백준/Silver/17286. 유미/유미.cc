#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    double dist;
    double yuumi_dist[3];
    double sides[3];
    pair<int, int> yuumi;
    pair<int, int> pos[3];

    cin >> yuumi.first >> yuumi.second;
    cin >> pos[0].first >> pos[0].second;
    cin >> pos[1].first >> pos[1].second;
    cin >> pos[2].first >> pos[2].second;
    sides[0] = sqrt(pow(pos[0].first - pos[1].first, 2) + pow(pos[0].second - pos[1].second, 2));
    sides[1] = sqrt(pow(pos[1].first - pos[2].first, 2) + pow(pos[1].second - pos[2].second, 2));
    sides[2] = sqrt(pow(pos[2].first - pos[0].first, 2) + pow(pos[2].second - pos[0].second, 2));

    yuumi_dist[0] = sqrt(pow(yuumi.first - pos[0].first, 2) + pow(yuumi.second - pos[0].second, 2));
    yuumi_dist[1] = sqrt(pow(yuumi.first - pos[1].first, 2) + pow(yuumi.second - pos[1].second, 2));
    yuumi_dist[2] = sqrt(pow(yuumi.first - pos[2].first, 2) + pow(yuumi.second - pos[2].second, 2));

    dist = yuumi_dist[0] + sides[0] + sides[1];
    dist = min(dist, yuumi_dist[0] + sides[2] + sides[1]);
    dist = min(dist, yuumi_dist[1] + sides[1] + sides[2]);
    dist = min(dist, yuumi_dist[1] + sides[0] + sides[2]);
    dist = min(dist, yuumi_dist[2] + sides[2] + sides[0]);
    dist = min(dist, yuumi_dist[2] + sides[1] + sides[0]);

    cout << (int)dist; 
}