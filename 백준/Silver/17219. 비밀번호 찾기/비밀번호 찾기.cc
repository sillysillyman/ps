#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    string addr, pwd;
    map<string, string> addr_to_pwd;

    cin >> N >> M;
    while (N--) {
        cin >> addr >> pwd;
        addr_to_pwd[addr] = pwd;
    }
    while (M--) {
        cin >> addr;
        cout << addr_to_pwd[addr] << '\n';
    }
}