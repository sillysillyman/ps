#include <cmath>
#include <cstdio>

using namespace std;

int main() {
  double x1, y1, r1, x2, y2, r2, d;

  scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
  d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  if (d >= r1 + r2)
    printf("%.3lf", 0.0);
  else if (d <= abs(r1 - r2))
    printf("%.3lf", M_PI * r2 * r2);
  else {
    double theta1 = acos((r1 * r1 - r2 * r2 + d * d) / (2 * r1 * d));
    double theta2 = acos((r2 * r2 - r1 * r1 + d * d) / (2 * r2 * d));

    printf("%.3lf", r1 * r1 * (theta1 - sin(theta1) * cos(theta1)) +
                        r2 * r2 * (theta2 - sin(theta2) * cos(theta2)));
  }
}