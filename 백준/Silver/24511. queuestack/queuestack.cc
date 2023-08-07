#include <iostream>
#include <deque>

using namespace std;

bool is_queue[100000];
deque<int> qs;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    int num;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> is_queue[i];
        is_queue[i] ^= 1;
    }
    for (int i = 0; i < N; i++) {
        cin >> num;
        if (is_queue[i]) qs.push_back(num);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> num;
        qs.push_front(num);
        cout << qs.back() << ' ';
        qs.pop_back();
    }
}