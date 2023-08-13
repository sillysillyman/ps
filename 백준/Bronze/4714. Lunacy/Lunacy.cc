#include <iostream>

using namespace std;

int main() {
    double weight;

    while (true) {
        cin >> weight;
        if (weight < 0) break;
        cout << fixed;
        cout.precision(2);
        cout << "Objects weighing " << weight << " on Earth will weigh " << 0.167*weight << " on the moon.\n";
    }
}