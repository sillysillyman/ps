#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, divisor;
    vector<int> num_of_divisors;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> divisor;
        num_of_divisors.push_back(divisor);
    }
    sort(num_of_divisors.begin(), num_of_divisors.end());
    cout << num_of_divisors.front()*num_of_divisors.back() << endl;
}