#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, sum = 0;
    vector<int> A, B;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        A.push_back(num);
    }
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        B.push_back(num);
    }
    
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (int i = 0; i < N; i++) {
        sum += A[i]*B[i];
    }
    cout << sum;
}