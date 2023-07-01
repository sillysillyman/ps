#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string line;
    vector<string> words;

    getline(cin, line);

    int npos;

    npos = line.find_first_not_of(' ');
    line.erase(0, npos);
    npos = line.find_last_not_of(' ');
    line.erase(npos + 1);

    istringstream iss(line);
    string buffer;

    while (getline(iss, buffer, ' ')) {
        words.push_back(buffer);
    }
    cout << words.size();
}