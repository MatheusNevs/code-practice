#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int funcionarios, clientes, tempo = 0;
    cin >> funcionarios >> clientes;
    vector<pair<int, int>> caixas(funcionarios);
    vector<int> produtos(clientes);
    bool estaNaFila = false;

    for (int i = 0; i < funcionarios; i++) {
        caixas[i].first = 0;
        cin >> caixas[i].second;
    }

    for (int i = 0; i < clientes; i++) {
        cin >> produtos[i];
    } 

    for (int i = 0; i < clientes; i++){
        auto menor = *min_element(caixas.begin(), caixas.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });
        estaNaFila = false;
        for (int j = 0; j < funcionarios; j++){
            if (caixas[j].first == menor.first & !estaNaFila){
                tempo += caixas[j].first;
                caixas[j].first = produtos[i]*caixas[j].second;
                estaNaFila = true;
            } else {
                if (caixas[j].first - menor.first >= 0)
                    caixas[j].first -= menor.first;
                else
                caixas[j].first = 0;
            }
        }
    }

    auto maior = max_element(caixas.begin(), caixas.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;});
    tempo += (*maior).first;

    cout << tempo << "\n";
    return 0;
}
