#include <iostream>

using namespace std;

int main() {
    int min_price = 2000;
    int set_price = -50;
    int hamburgers[3];
    int beverages[2];

    for (int i = 0; i < 3; i++) {
        cin >> hamburgers[i];
        min_price = min(min_price, hamburgers[i]);
    }
    set_price += min_price;
    min_price = 2000;
    for (int i = 0; i < 2; i++) {
        cin >> beverages[i];
        min_price = min(min_price, beverages[i]);
    }
    set_price += min_price;
    cout << set_price;
}