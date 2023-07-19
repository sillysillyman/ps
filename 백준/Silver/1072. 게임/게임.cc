#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double X, Y, Z;
    int cnt = -1;

    cin >> X >> Y;
    Z = floor(100*Y/X);

    int low = 1;
    int high = 1000000000;

    while (low <= high) {
        int mid = (high + low)/2;
        double rate = floor(100*(Y + mid)/(X + mid));

        if (rate > Z) {
            high = mid - 1;
            cnt = mid;
        } else low = mid + 1;
    }
    cout << cnt;
}