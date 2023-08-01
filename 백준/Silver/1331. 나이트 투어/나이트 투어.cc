#include <iostream>

using namespace std;

int main() {
    bool is_alreay_printed = false;
    int chessboard[6][6] = {0, };
    pair<int, int> init;
    pair<int, int> prev;
    pair<int, int> curr;
    string pos;

    for (int i = 0; i < 36; i++) {
        cin >> pos;

        int r = 6 - (pos[1] - '0');
        int c = pos[0] - 'A';

        if (chessboard[r][c] && !is_alreay_printed) {
            cout << "Invalid\n";
            is_alreay_printed = true;
        } else chessboard[r][c] = 1;
        if (i == 0) {
            curr = {r, c};
            init = {r, c};
        }
        else {
            prev = curr;
            curr = {r, c};

            bool valid = false;

            if (make_pair(prev.first - 2, prev.second - 1) == curr) valid = true;
            else if (make_pair(prev.first - 2, prev.second + 1) == curr) valid = true;
            else if (make_pair(prev.first - 1, prev.second + 2) == curr) valid = true;
            else if (make_pair(prev.first + 1, prev.second + 2) == curr) valid = true;
            else if (make_pair(prev.first + 2, prev.second + 1) == curr) valid = true;
            else if (make_pair(prev.first + 2, prev.second - 1) == curr) valid = true;
            else if (make_pair(prev.first + 1, prev.second - 2) == curr) valid = true;
            else if (make_pair(prev.first - 1, prev.second - 2) == curr) valid = true;
            if (i == 35) {
                valid = false;
                if (make_pair(curr.first - 2, curr.second - 1) == init) valid = true;
                else if (make_pair(curr.first - 2, curr.second + 1) == init) valid = true;
                else if (make_pair(curr.first - 1, curr.second + 2) == init) valid = true;
                else if (make_pair(curr.first + 1, curr.second + 2) == init) valid = true;
                else if (make_pair(curr.first + 2, curr.second + 1) == init) valid = true;
                else if (make_pair(curr.first + 2, curr.second - 1) == init) valid = true;
                else if (make_pair(curr.first + 1, curr.second - 2) == init) valid = true;
                else if (make_pair(curr.first - 1, curr.second - 2) == init) valid = true;
            }
            if (!valid && !is_alreay_printed) {
                cout << "Invalid\n";
                is_alreay_printed = true;
            }
        }
    }
    if (!is_alreay_printed) cout << "Valid";
}