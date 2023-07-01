#include <iostream>

using namespace std;

int main() {
    int N; // N <= 1000
    int cnt = 0;
    
    cin >> N;

    if (N < 100) cout << N;
    else {
        if (N == 1000) N = 999;
        cnt = 99;
        for (int i = 100; i <= N; i++) {
            int units = i%10;
            int tens = (i%100)/10;
            int hundreds = i/100;
            if (2*tens == units + hundreds) cnt++;
        }
        cout << cnt;
    }
}