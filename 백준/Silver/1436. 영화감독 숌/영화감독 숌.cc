#include <iostream>
#include <string>

using namespace std;

bool is_666(int num) {
    string s = to_string(num);
    string apocalypse_num = "666";
    if (s.find(apocalypse_num) == string::npos) return false;
    else return true;
}

int main() {
    int N;
    int cnt = 0;
    int num = 1;

    cin >> N;
    while (1) {
        if (is_666(num)) {
            cnt++;
            if (cnt == N) {
                cout << num;
                break;
            }
        }
        num++;
    }
}