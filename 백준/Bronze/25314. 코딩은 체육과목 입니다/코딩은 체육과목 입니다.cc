#include <iostream>

using namespace std;

int main() {
    int N;
    string type_name = "";
    
    cin >> N;
    while (N) {
        type_name += "long ";
        N -= 4;
    }
    type_name += "int";
    cout << type_name;
}