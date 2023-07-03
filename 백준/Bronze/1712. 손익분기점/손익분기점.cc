#include <iostream>

using namespace std;

int main() {
    int A, B, C;
    int sale_cnt = 0;

    cin >> A >> B >> C;
    if (B >= C) sale_cnt = -1;
    else {
        while (sale_cnt <= A/(C - B)) {
            sale_cnt+=1;
        }
    }
    cout << sale_cnt;
}