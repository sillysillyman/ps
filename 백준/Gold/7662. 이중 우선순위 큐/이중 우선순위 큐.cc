#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    int k;

    cin >> T;
    while (T--) {
        char cmd;
        int num;
        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        map<int, int> cnt;
        
        cin >> k;
        while (k--) {
            cin >> cmd >> num;
            while (!min_heap.empty() && cnt[min_heap.top()] == 0) min_heap.pop();
            while (!max_heap.empty() && cnt[max_heap.top()] == 0) max_heap.pop();
            if (cmd == 'I') {
                max_heap.push(num);
                min_heap.push(num);
                cnt[num]++;
            } else if (cmd == 'D') {
                if (num == -1 && !min_heap.empty() && cnt[min_heap.top()]) {
                    cnt[min_heap.top()]--;
                    min_heap.pop();
                } else if (num == 1 && !max_heap.empty() && cnt[max_heap.top()]) {
                    cnt[max_heap.top()]--;
                    max_heap.pop();
                }
            }
        }
        while (!min_heap.empty() && cnt[min_heap.top()] == 0) min_heap.pop();
        while (!max_heap.empty() && cnt[max_heap.top()] == 0) max_heap.pop();
        // cout << max_heap.top() << endl;
        // cout << min_heap.top() << endl;
        // cout << "max_heap: ";
        // while (!max_heap.empty()) {
        //     cout << max_heap.top() << ' ';
        //     max_heap.pop();
        // }
        // cout << '\n';
        // cout << "min_heap: ";
        // while (!min_heap.empty()) {
        //     cout << min_heap.top() << ' ';
        //     min_heap.pop();
        // }
        // cout << endl;
        // for (auto i : cnt) {
        //     cout << i.first << ": " << i.second << ", ";
        // }
        // if (max_heap.empty() && min_heap.empty()) cout << "EMPTY\n";
        // else cout << max_heap.top() << " " << min_heap.top() << '\n';
        if (max_heap.empty() && min_heap.empty()) cout << "EMPTY\n";
        else cout << max_heap.top() << " " << min_heap.top() << '\n';
    }
}
// 16: 0, -5643: 0, 123: 0
// max: 123
// min: