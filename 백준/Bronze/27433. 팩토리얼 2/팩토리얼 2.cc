#include <iostream>
#include <functional>

using namespace std;

int main() {
    int N;
    function<long long(int)> factorial = [&factorial](int n) -> long long {
        if (n <= 1) return 1;
        else return n*factorial(n - 1);
    };

    cin >> N;
    cout << factorial(N);
}