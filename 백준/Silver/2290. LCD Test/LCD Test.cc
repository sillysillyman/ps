#include <iostream>

using namespace std;

char display[23][130];

int main() {
    int s;
    int cur = 0;
    int len;
    string n;

    cin >> s >> n;
    len = n.length();
    for (char c : n) {
        switch (c - '0') {
            case 0:
                for (int i = 0; i < 2*s + 3; i++) {
                    for (int j = cur; j < cur + s + 3; j++) {
                        if (j == cur + s + 2) display[i][j] = ' ';
                        else if (j == cur || j == cur + s + 1) {
                            if (i == 0 || i == s + 1 || i == 2*s + 2) display[i][j] = ' ';
                            else display[i][j] = '|';
                        } else {
                            if (i == 0 || i == 2*s + 2) display[i][j] = '-';
                            else display[i][j] = ' ';
                        }
                    }
                }
                break;
            case 1:
                for (int i = 0; i < 2*s + 3; i++) {
                    for (int j = cur; j < cur + s + 3; j++) {
                        if (j == cur + s + 1) {
                            if (i == 0 || i == s + 1 || i == 2*s + 2) display[i][j] = ' ';
                            else display[i][j] = '|';
                        } else display[i][j] = ' ';
                    }
                }
                break;
            case 2:
                for (int i = 0; i < 2*s + 3; i++) {
                    for (int j = cur; j < cur + s + 3; j++) {
                        if (j == cur + s + 2) display[i][j] = ' ';
                        else if (j == cur) {
                            if (i == 0 || i == s + 1 || i == 2*s + 2) display[i][j] = ' ';
                            else if (i > s + 1) display[i][j] = '|';
                            else display[i][j] = ' ';
                        } else if (j == cur + s + 1) {
                            if (i == 0 || i == s + 1 || i == 2*s + 2) display[i][j] = ' ';
                            else if (i < s + 1) display[i][j] = '|';
                            else display[i][j] = ' ';
                        } else {
                            if (i == 0 || i == s + 1 || i == 2*s + 2) display[i][j] = '-';
                            else display[i][j] = ' ';
                        }
                    }
                }
                break;
            case 3:
                for (int i = 0; i < 2*s + 3; i++) {
                    for (int j = cur; j < cur + s + 3; j++) {
                        if (j == cur || j == cur + s + 2) display[i][j] = ' ';
                        else if (j == cur + s + 1) {
                            if (i == 0 || i == s + 1 || i == 2*s + 2) display[i][j] = ' ';
                            else display[i][j] = '|';
                        } else {
                            if (i == 0 || i == s + 1 || i == 2*s + 2) display[i][j] = '-';
                            else display[i][j] = ' ';
                        }
                    }
                }
                break;
            case 4:
                for (int i = 0; i < 2*s + 3; i++) {
                    for (int j = cur; j < cur + s + 3; j++) {
                        if (i == 0 || i == 2*s + 2 || j == cur + s + 2) display[i][j] = ' ';
                        else if (j == cur) {
                            if (i == 0 || i == s + 1 || i == 2*s + 2) display[i][j] = ' ';
                            else if (i < s + 1) display[i][j] = '|';
                            else display[i][j] = ' ';
                        } else if (j == cur + s + 1) {
                            if (i == 0 || i == s + 1 || i == 2*s + 2) display[i][j] = ' ';
                            else display[i][j] = '|';
                        }
                        else {
                            if (i == s + 1) display[i][j] = '-';
                            else display[i][j] = ' ';
                        }
                    }
                }
                break;
            case 5:
                for (int i = 0; i < 2*s + 3; i++) {
                    for (int j = cur; j < cur + s + 3; j++) {
                        if (j == cur + s + 2) display[i][j] = ' ';
                        else if (j == cur) {
                            if (i == 0 || i == s + 1 || i == 2*s + 2) display[i][j] = ' ';
                            else if (i < s + 1) display[i][j] = '|';
                            else display[i][j] = ' ';
                        } else if (j == cur + s + 1) {
                            if (i == 0 || i == s + 1 || i == 2*s + 2) display[i][j] = ' ';
                            else if (i > s + 1) display[i][j] = '|';
                            else display[i][j] = ' ';
                        } else {
                            if (i == 0 || i == s + 1 || i == 2*s + 2) display[i][j] = '-';
                            else display[i][j] = ' ';
                        }
                    }
                }
                break;
            case 6:
                for (int i = 0; i < 2*s + 3; i++) {
                    for (int j = cur; j < cur + s + 3; j++) {
                        if (j == cur + s + 2) display[i][j] = ' ';
                        else if (j == cur) {
                            if (i == 0 || i == s + 1 || i == 2*s + 2) display[i][j] = ' ';
                            else display[i][j] = '|';
                        } else if (j == cur + s + 1) {
                            if (i == 0 || i == s + 1 || i == 2*s + 2) display[i][j] = ' ';
                            else if (i > s + 1) display[i][j] = '|';
                            else display[i][j] = ' ';
                        } else {
                            if (i == 0 || i == s + 1 || i == 2*s + 2) display[i][j] = '-';
                            else display[i][j] = ' ';
                        }
                    }
                }
                break;
            case 7:
                for (int i = 0; i < 2*s + 3; i++) {
                    for (int j = cur; j < cur + s + 3; j++) {
                        if (i == s + 1 || i == 2*s + 2 || j == cur || j == cur + s + 2) display[i][j] = ' ';
                        else if (j == cur + s + 1) {
                            if (i == 0 || i == s + 1 || i == 2*s + 2) display[i][j] = ' ';
                            else display[i][j] = '|';
                        } else {
                            if (i == 0) display[i][j] = '-';
                            else display[i][j] = ' ';
                        }
                    }
                }
                break;
            case 8:
                for (int i = 0; i < 2*s + 3; i++) {
                    for (int j = cur; j < cur + s + 3; j++) {
                        if (j == cur + s + 2) display[i][j] = ' ';
                        else if (j == cur) {
                            if (i == 0 || i == s + 1 || i == 2*s + 2) display[i][j] = ' ';
                            else display[i][j] = '|';
                        } else if (j == cur + s + 1) {
                            if (i == 0 || i == s + 1 || i == 2*s + 2) display[i][j] = ' ';
                            else display[i][j] = '|';
                        } else {
                            if (i == 0 || i == s + 1 || i == 2*s + 2) display[i][j] = '-';
                            else display[i][j] = ' ';
                        }
                    }
                }
                break;
            case 9:
                for (int i = 0; i < 2*s + 3; i++) {
                    for (int j = cur; j < cur + s + 3; j++) {
                        if (j == cur + s + 2) display[i][j] = ' ';
                        else if (j == cur) {
                            if (i == 0 || i == s + 1 || i == 2*s + 2) display[i][j] = ' ';
                            else if (i < s + 1) display[i][j] = '|';
                            else display[i][j] = ' ';
                        } else if (j == cur + s + 1) {
                            if (i == 0 || i == s + 1 || i == 2*s + 2) display[i][j] = ' ';
                            else display[i][j] = '|';
                        } else {
                            if (i == 0 || i == s + 1 || i == 2*s + 2) display[i][j] = '-';
                            else display[i][j] = ' ';
                        }
                    }
                }
                break;
        }
        cur += s + 3;
    }
    for (int i = 0; i < 2*s + 3; i++) {
        for (int j = 0; j < (s + 3)*len - 1; j++) {
            if (display[i][j] != ' ' && display[i][j] != '|' && display[i][j] != '-') continue;
            cout << display[i][j];
        }
        cout << '\n';
    }
    // cout << '\n';
    // cout << '\n';
    // cout << display[1][3];
}
//      --   --        --   --   --   --   --   --  
//   |    |    | |  | |    |       | |  | |  | |  | 
//   |    |    | |  | |    |       | |  | |  | |  | 
//      --   --   --   --   --        --   --       
//   | |       |    |    | |  |    | |  |    | |  | 
//   | |       |    |    | |  |    | |  |    | |  | 
//      --   --        --   --        --   --   --  