#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    string pokemon;
    vector<string> pokemons;
    map<string, int> pokemons_dict;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> pokemon;
        pokemons.push_back(pokemon);
        pokemons_dict.insert({pokemon, i});
    }
    for (int i = 1; i <= M; i++) {
        cin >> pokemon;
        if (isdigit(pokemon[0])) cout << pokemons[stoi(pokemon) - 1] << '\n';
        else cout << pokemons_dict[pokemon] << '\n';
    }
}