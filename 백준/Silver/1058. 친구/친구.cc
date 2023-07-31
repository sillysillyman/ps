#include <iostream>

using namespace std;

const int INF = 987654321;

int main() {
    int N;
    int graph[50][50];
    string str;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < N; j++) {
            if (str[j] == 'Y') graph[i][j] = 1;
            else if (i == j) graph[i][j] = 0;
            else graph[i][j] = INF;
        }
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    int max_friends = 0;
    
    for (int i = 0; i < N; i++) {
        int friends = 0;
        
        for (int j = 0; j < N; j++) {
            if (graph[i][j] != 0 && graph[i][j] <= 2) friends++;
        }
        max_friends = max(max_friends, friends);
    }
    cout << max_friends;
}