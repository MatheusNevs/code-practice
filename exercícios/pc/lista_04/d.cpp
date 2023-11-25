#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,q;
    cin >> n >> q;
    vector<int> qt_doentes(n+1,0);
    vector<int> delta_doentes(n+1,0);
    vector<int> delta_operacoes(n+1,0);


    for (int i = 0; i<n; i++){
        int quantidade;
        cin >> quantidade;
        qt_doentes[i] = quantidade;
        if (i == 0){
            delta_doentes[0] = quantidade;
        } else {
            delta_doentes[i] = quantidade - qt_doentes[i-1];
        }
    }

  
    while (q--){
        int inicio, fim, adicional;
        cin >> inicio >> fim >> adicional;
        delta_doentes[inicio - 1] -= adicional;
        delta_doentes[fim] += adicional;
        delta_operacoes[inicio - 1] += 1;
        delta_operacoes[fim] -= 1;

    }


    long long resultado = 0, operacoes = 0, soma = 0;
    for ( int i = 0; i < n; i++) {
        resultado = resultado + delta_doentes[i];
        operacoes = operacoes + delta_operacoes[i];
        if (resultado > 0){
            soma = soma + operacoes;
        }
    }

    cout << soma << "\n";

    return 0;
}