#include <iostream>

using namespace std;

int main() {
    int N;
    int zero_cnt = 0;

    cin >> N;
    zero_cnt += N/5;
    zero_cnt += N/25;
    zero_cnt += N/125;
    cout << zero_cnt;
}