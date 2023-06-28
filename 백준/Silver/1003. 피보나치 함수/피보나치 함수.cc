#include <iostream>

using namespace std;

int fibo[41] = {0, 1,};

int fibonacci(int n) {
    if (n <= 1) {
        return fibo[n];
    } else {
        for (int i = 2; i <= n; ++i) {
            fibo[i] = fibo[i- 2] + fibo[i - 1];
        }
        return fibo[n];
    }
}

int main() {
    int T, n;
        
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> n;
        if (n == 0) {
            cout << "1 0" << endl;
        } else {
            cout << fibonacci(n - 1) << " " << fibonacci(n) << endl;
        }
    }
}