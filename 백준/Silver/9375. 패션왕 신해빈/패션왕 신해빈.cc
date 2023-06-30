#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int T;
    int n;
    string clothes_name, clothes_type;

    cin >> T;
    while (T--) {
        int ans = 1;
        map<string, int> clothes;

        cin >> n;
        while (n--) {
            cin >> clothes_name >> clothes_type;
            clothes[clothes_type]++;
        }
        for (auto i: clothes) ans *= (i.second + 1);
        cout << ans - 1 << endl;
    }
}