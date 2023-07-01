#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    int file_len;
    string file;
    vector<string> files;
    string pattern = "";

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> file;
        file_len = file.length();
        files.push_back(file);
    }
    if (files.size() == 1) {
        cout << files[0];
    } else {
        for (int i = 0; i < file_len; i++) {
            bool success = false;
            char c = files[0][i];
            for (auto file : files) {
                if (c == file[i]) success = true;
                else {
                    success = false;
                    break;
                }
            }
            if (success) pattern += c;
            else pattern += '?';
        }
        cout << pattern;
    }
}