#include <iostream>
#include <map>

using namespace std;

int main() {
    int N;
    string A, B;
    int cnt = 0;
    map<string, int> people;

    cin >> N;
    while (N--) {
        cin >> A >> B;
        if (A == "ChongChong" || B == "ChongChong" || people[A] >= 1 || people[B] >= 1) {
            people[A]++;
            people[B]++;
        }
    }
    for (auto person : people) {
        if (person.second >= 1) cnt++;
    }
    cout << cnt;
}