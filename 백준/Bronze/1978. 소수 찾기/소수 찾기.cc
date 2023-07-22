#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int num) {
    if (num <= 1) return false;
    else if (num <= 3) return true;
    else if (num%2 == 0) return false;
    else {
        int root = int(sqrt(num));
        
        for (int i = 3; i <= root; i++) {
            if (num%i == 0) return false;
        }
    }
    return true;
}

int main() {
    int N;
    int num;
    int cnt = 0;

    cin >> N;
    while (N--) {
        cin >> num;
        if (is_prime(num)) cnt++;
    }
    cout << cnt;
}