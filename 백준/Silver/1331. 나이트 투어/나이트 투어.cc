#include <iostream>

using namespace std;

bool is_inside(int r, int c) {
    return r >= 0 && r < 6 && c >= 0 && c < 6;
}

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
            // cout << "visited!\n";
            cout << "Invalid\n";
            is_alreay_printed = true;
            // return 0;
        } else chessboard[r][c] = 1;
        if (i == 0) {
            curr = {r, c};
            init = {r, c};
        }
        else {
            prev = curr;
            // cout << "prev: " << prev.first << " " << prev.second << endl;
            curr = {r, c};
            // cout << "curr: " << curr.first << " " << curr.second << endl;

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
                // cout << "curr: " << curr.first << ", " << curr.second << endl;
                // cout << "init: " << init.first << ", " << init.second << endl;
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
                // cout << "invalid movement\n";
                cout << "Invalid\n";
                is_alreay_printed = true;
                // return 0;
            }
        }
    }
    if (!is_alreay_printed) cout << "Valid";
}
// 6 1 1 1 1 1 1
// 5 1 1 1 1 1 1
// 4 1 1 1 1 1 1
// 3 1 1 1 1 1 1
// 2 1 1 1 1 1 1
// 1 1 1 1 1 1 1 
//   A B C D E F