#include <iostream>
#include <map>

using namespace std;

map<char, int> shortcuts;

int main() {
    int N;

    cin >> N;
    cin.ignore();
    while (N--) {
        int char_cnt = 0;
        bool has_shortcut = false;
        string command;
        
        getline(cin, command);
        for (int i = 0; i < command.length(); i++) {
            if (command[i] != ' ' && char_cnt == 0 && shortcuts[tolower(command[i])] == 0) {
                shortcuts[tolower(command[i])]++;
                command.insert(i, "[");
                command.insert(i + 2, "]");
                has_shortcut = true;
                break;
            } else if (command[i] == ' ') char_cnt = 0;
            else char_cnt++;
        }
        if (has_shortcut) {
            cout << command << '\n';
            continue;
        } else {
            for (int i = 0; i < command.length(); i++) {
                if (command[i] != ' ' && shortcuts[tolower(command[i])] == 0) {
                    shortcuts[tolower(command[i])]++;
                    command.insert(i, "[");
                    command.insert(i + 2, "]");
                    break;
                }
            }
        }
        cout << command << '\n';
    }
}