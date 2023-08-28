#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<int> split(string str, char delimiter) {
    istringstream iss(str);
    string buffer;
    vector<int> ret;

    while (getline(iss, buffer, delimiter)) ret.push_back(stoi(buffer));
    return ret;
}

int main() {
    string kda;
    vector<int> v;

    cin >> kda;
    v = split(kda, '/');
    if (v[1] == 0 || v[0] + v[2] < v[1]) cout << "hasu";
    else cout << "gosu";
}