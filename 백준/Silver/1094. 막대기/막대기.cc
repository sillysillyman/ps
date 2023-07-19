#include <iostream>
#include <array>

using namespace std;

int main() {
    int X;
    array<int, 7> stick = {64, 32, 16, 8, 4, 2, 1};
    int cnt = 0;

    cin >> X;
    for (int i = 0; i < stick.size(); i++) {
        if (X >= stick[i]) {
            X -= stick[i];
            cnt++;
        }        
    }
    cout << cnt;
}