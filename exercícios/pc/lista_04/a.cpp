#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    long long n, q, soma = 0;
    vector<long long> somas;
    somas.push_back(0);


    cin >> n >> q;
    for (int i = 0; i < n; i++){
        long long numero;
        cin >> numero;
        soma += numero; 
        somas.push_back(soma);
    }


    for (int i = 0; i < q; i++){
        long long inicio, fim, resultado;
        cin >> inicio >> fim;
        resultado = somas[fim] - somas[inicio - 1];
        cout << resultado << "\n";
    }


    return 0;
}