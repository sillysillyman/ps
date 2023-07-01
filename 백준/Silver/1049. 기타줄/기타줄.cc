#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    map<int, int> prices;

    cin >> N >> M;
    while (M--) {
        int package_price, single_price;
        cin >> package_price >> single_price;
        if (prices.find(package_price) != prices.end()) {
            if (prices[package_price] > single_price) prices[package_price] = single_price;
        } else {
            prices[package_price] = single_price;
        }
    }
    
    int min_package_price = prices.begin()->first;
    int min_single_price = min_element(prices.begin(), prices.end(),
            [](auto l, auto r) {
                return l.second < r.second;
            })->second;

    if (min_package_price > 6*min_single_price) {
        cout << min_single_price*N;
    } else {
        int min_price = 0;
        while (N > 0) {
            if (N >= 6) N -= 6;
            else break;
            min_price += min_package_price;
        }
        if (min_package_price < min_single_price*N) min_price += min_package_price;
        else min_price += min_single_price*N;
        cout << min_price;
    }
}