#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio;
    cin.tie(NULL);
    cout.tie(NULL);

    stack<int> carrinhos;
    set<pair<int, int>> caixas;
    int funcionarios, clientes;
    cin >> funcionarios >> clientes;

    for (int i = 0; i < funcionarios; i++){
        int peso;
        cin >> peso;
        caixas.push((0, peso));
    }

    for (int i = 0; i < clientes; i++){
        int cliente;
        cin >> cliente;
        carrinhos.push(cliente);
    }




    return 0;
}