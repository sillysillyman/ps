#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct point {
    int x, y;
};

int main() {
    int N;
    double max_area = 0;
    vector<point> points;

    cin >> N;
    for (int i = 0; i < N; i++) {
        point p;

        cin >> p.x >> p.y;
        points.push_back(p);
    }

    double area;

    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                point p1 = points[i];
                point p2 = points[j];
                point p3 = points[k];
                
                area = 0.5*abs((p1.x*p2.y + p2.x*p3.y + p3.x*p1.y) - (p2.x*p1.y + p3.x*p2.y + p1.x*p3.y));
                max_area = max(max_area, area);
            }
        }
    }
    cout << fixed;
    cout.precision(9);
    cout << max_area;
}