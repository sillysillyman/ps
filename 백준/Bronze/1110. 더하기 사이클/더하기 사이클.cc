#include <iostream>

using namespace std;

int main() {
    int N;
    int cycle_cnt = 0;

    cin >> N;
    
    int new_N = N;

    while (1) {
        new_N = (new_N%10)*10 + ((new_N/10) + (new_N%10))%10;
        cycle_cnt++;
        if (new_N == N) break;
    }
    cout << cycle_cnt;
}