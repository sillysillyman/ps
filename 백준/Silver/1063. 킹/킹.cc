#include <iostream>
#include <utility>
#include <string>
#include <map>

using namespace std;

int main() {
    int N;
    string init_king_pos, init_stone_pos, cmd;
    enum cmds {R, L, B, T, RT, LT, RB, LB};
    map<string, int> cmds = {{"R", R}, {"L", L}, {"B", B}, {"T", T}, {"RT", RT}, {"LT", LT}, {"RB", RB}, {"LB", LB}};
    
    cin >> init_king_pos >> init_stone_pos >> N;

    pair<int, int> king_pos = make_pair('8' - int(init_king_pos[1]), int(init_king_pos[0]) - 'A');
    pair<int, int> stone_pos = make_pair('8' - int(init_stone_pos[1]), int(init_stone_pos[0]) - 'A');

    while (N--) {
        cin >> cmd;
        switch (cmds[cmd]) {
            case R:
                if (king_pos.second == 7) break;
                if ((stone_pos.first == king_pos.first) && (stone_pos.second == king_pos.second + 1)) {
                    if (stone_pos.second == 7) break;
                    else stone_pos.second++;
                }
                king_pos.second++;
                break;
            case L:
                if (king_pos.second == 0) break;
                if ((stone_pos.first == king_pos.first) && (stone_pos.second == king_pos.second - 1)) {
                    if (stone_pos.second == 0) break;
                    else stone_pos.second--;
                } 
                king_pos.second--;
                break;
            case B:
                if (king_pos.first == 7) break;
                if ((stone_pos.second == king_pos.second) && (stone_pos.first == king_pos.first + 1)) {
                    if (stone_pos.first == 7) break;
                    else stone_pos.first++;
                }
                king_pos.first++;
                break;
            case T:
                if (king_pos.first == 0) break;
                if ((stone_pos.second == king_pos.second) && (stone_pos.first == king_pos.first - 1)) {
                    if (stone_pos.first == 0) break;
                    else stone_pos.first--;
                }
                king_pos.first--;
                break;
            case RT:
                if ((king_pos.first == 0) || (king_pos.second == 7)) break;
                if ((stone_pos.first == king_pos.first - 1) && (stone_pos.second == king_pos.second + 1)) {
                    if ((stone_pos.first == 0) || (stone_pos.second == 7)) break;
                    else {
                        stone_pos.first--;
                        stone_pos.second++;
                    }
                }
                king_pos.first--;
                king_pos.second++;
                break;
            case LT:
                if ((king_pos.first == 0) || (king_pos.second == 0)) break;
                if ((stone_pos.first == king_pos.first - 1) && (stone_pos.second == king_pos.second - 1)) {
                    if ((stone_pos.first == 0) || (stone_pos.second == 0)) break;
                    else {
                        stone_pos.first--;
                        stone_pos.second--;
                    }
                }
                king_pos.first--;
                king_pos.second--;
                break;
            case RB:
                if ((king_pos.first == 7) || (king_pos.second == 7)) break;
                if ((stone_pos.first == king_pos.first + 1) && (stone_pos.second == king_pos.second + 1)) {
                    if ((stone_pos.first == 7) || (stone_pos.second == 7)) break;
                    else {
                        stone_pos.first++;
                        stone_pos.second++;
                    }
                }
                king_pos.first++;
                king_pos.second++;
                break;
            case LB:
                if ((king_pos.first == 7) || (king_pos.second == 0)) break;
                if ((stone_pos.first == king_pos.first + 1) && (stone_pos.second == king_pos.second - 1)) {
                    if ((stone_pos.first == 7) || (stone_pos.second == 0)) break;
                    else {
                        stone_pos.first++;
                        stone_pos.second--;
                    }
                }
                king_pos.first++;
                king_pos.second--;
                break;
        }
    }
    cout << char(king_pos.second + 'A') <<  8 - king_pos.first << endl;
    cout << char(stone_pos.second + 'A') <<  8 - stone_pos.first << endl;
}