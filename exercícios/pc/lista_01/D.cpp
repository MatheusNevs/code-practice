#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    vector<string> nomes;
    vector<string> nomesCopia;

    cin >> n;
    for (int i = 0; i < n; i++) {
        string nome;
        cin >> nome;
        nomes.push_back(nome);
        nomesCopia.push_back(nome);
    }

    sort(nomesCopia.begin(), nomesCopia.end());
    
    for (int i = 0; i < n; i++) {
        auto pos = find(nomesCopia.begin(), nomesCopia.end(), nomes[i]);
        cout << distance(nomesCopia.begin(), pos) << " ";
    }

    return 0;
}
