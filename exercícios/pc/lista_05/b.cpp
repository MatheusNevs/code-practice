#include <bits/stdc++.h>
using namespace std;

long long encontrar_k(long long numero) {
    int numero_bits = 0;
    long long temp = numero;

    while (temp > 0) {
        temp >>= 1;
        numero_bits++;
    }

    int numero_significativo = 1<<(numero_bits - 1 );
    return numero_significativo - 1;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testes, n;
    cin >> testes;

    while (testes--){
        int resultado;
        cin >> n;
        resultado = encontrar_k(n);
        cout << resultado << "\n";
    }
    return 0;
}