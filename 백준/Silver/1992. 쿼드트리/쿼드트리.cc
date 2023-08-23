#include <iostream>

using namespace std;

int N;
int graph[64][64];

bool is_all_zero(int x, int y, int size) {
    bool ret = true;
    
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (graph[i][j] == 1) ret = false;
        }
    }
    return ret;
}

bool is_all_one(int x, int y, int size) {
    bool ret = true;
    
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (graph[i][j] == 0) ret = false;
        }
    }
    return ret;
}


void quad_tree(int x, int y, int size) {
    if (is_all_zero(x, y, size)) cout << 0;
    else if (is_all_one(x, y, size)) cout << 1;
    else {
        cout << '(';
        quad_tree(x, y, size/2);
        quad_tree(x, y + size/2, size/2);
        quad_tree(x + size/2, y, size/2);
        quad_tree(x + size/2, y + size/2, size/2);
        cout << ')';
    }
}

int main() {
    string line;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> line;
        for (int j = 0; j < N; j++) graph[i][j] = line[j] - '0';
    }
    quad_tree(0, 0, N);
}