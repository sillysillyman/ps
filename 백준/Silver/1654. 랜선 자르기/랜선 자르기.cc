#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_cuttable(vector<long long> lines, long long len, long long cnt) {
    int n = 0;

    for (int line : lines) {
        while (line >= len) {
            line -= len;
            n++;
        }
    }
    if (n >= cnt) return true;
    else return false;
}

int main() {
    int K, N;
    long long line;
    long long lower, upper;
    long long max_len = 0;
    vector<long long> lines;

    cin >> K >> N;
    while (K--) {
        cin >> line;
        lines.push_back(line);
    }
    lower = 1;
    upper = *max_element(lines.begin(), lines.end());
    while (lower <= upper) {
        long long mid = (lower + upper)/2;
        
        if (is_cuttable(lines, mid, N)) {
            lower = mid + 1;
            max_len = max(max_len, mid);
        } else upper = mid - 1;
    }
    cout << max_len;
}