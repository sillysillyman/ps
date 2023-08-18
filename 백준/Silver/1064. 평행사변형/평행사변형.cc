#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int xa, ya, xb, yb, xc, yc;

    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    if (xa == xb && xb == xc && xc == xa) {
        cout << -1;
        return 0;
    }
    else if ((double)(yb - ya)/(xb - xa) == (double)(yc - ya)/(xc - xa)) {
        cout << -1;
        return 0;
    }

    double ab = sqrt((xa - xb)*(xa - xb) + (ya - yb)*(ya - yb));
    double bc = sqrt((xb - xc)*(xb - xc) + (yb - yc)*(yb - yc));
    double ca = sqrt((xc - xa)*(xc - xa) + (yc - ya)*(yc - ya));
    double max_perimeter = max(2*(ab + bc), max(2*(bc + ca), 2*(ca + ab)));
    double min_perimeter = min(2*(ab + bc), min(2*(bc + ca), 2*(ca + ab)));;

    cout << fixed;
    cout.precision(11);
    cout << max_perimeter - min_perimeter;
}