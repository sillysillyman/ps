#include <iostream>

using namespace std;

int main() {
    int score;
    int sum = 0;
    
    for (int i = 0; i < 5; i++) {
        cin >> score;
        score = score < 40  ? 40 : score;
        sum += score;
    }
    cout << sum/5;
}