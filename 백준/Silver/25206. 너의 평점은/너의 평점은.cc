#include <iostream>

using namespace std;

int main() {
    string subject, grade;
    double credit, total_credit = 0, product = 0;

    for (int i = 0; i < 20; i++) {
        cin >> subject >> credit >> grade;
        if (grade == "A+") {
            product += 4.5*credit;
            total_credit += credit;
        } else if (grade == "A0") {
            product += 4.0*credit;
            total_credit += credit;
        } else if (grade == "B+") {
            product += 3.5*credit;
            total_credit += credit;
        } else if (grade == "B0") {
            product += 3.0*credit;
            total_credit += credit;
        } else if (grade == "C+") {
            product += 2.5*credit;
            total_credit += credit;
        } else if (grade == "C0") {
            product += 2.0*credit;
            total_credit += credit;
        } else if (grade == "D+") {
            product += 1.5*credit;
            total_credit += credit;
        } else if (grade == "D0") {
            product += 1.0*credit;
            total_credit += credit;
        } else if (grade == "F") total_credit += credit;
    }
    cout << fixed;
    cout.precision(6);
    if (!total_credit) cout << 0.0;
    else cout << product/total_credit;
}