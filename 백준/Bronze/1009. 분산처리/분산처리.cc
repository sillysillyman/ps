#include <iostream>

using namespace std;

int main() {
    int T;
    int a, b;

    cin >> T;

    while (T--) {
        int ans = 1;
        cin >> a >> b;
        b = !(b%4)?4:(b%4);
        while (b--) ans = (ans*a)%10;
        ans = !ans?10:ans;
        cout << ans << endl;
    }
}