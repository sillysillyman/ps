#include <iostream>
#include <map>

using namespace std;

int main() {
    int N;
    string mbti;
    map<string, int> mbtis;

    cin >> mbti;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string str;

        cin >> str;
        mbtis[str]++;
    }
    cout << mbtis[mbti];
}