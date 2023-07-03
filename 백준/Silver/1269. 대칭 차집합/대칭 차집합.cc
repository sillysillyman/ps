#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    int num;
    vector<int> A;
    vector<int> B;
    
    cin >> N >> M;
    while (N--) {
        cin >> num;
        A.push_back(num);
    }
    while (M--) {
        cin >> num;
        B.push_back(num);
    }
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());

    vector<int> C(A.size() + B.size());

    auto iter = set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), C.begin());
    cout << (iter - C.begin());
}