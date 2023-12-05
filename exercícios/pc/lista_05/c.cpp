#include <bits/stdc++.h>
using namespace std;

// Função para obter o bit mais significativo de um número
int mostSignificantBit(int n) {
    int bit = 0;
    while (n >>= 1) {
        bit++;
    }
    return bit;
}

bool compare(int a, int b) {
    return mostSignificantBit(a) < mostSignificantBit(b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testes, n;
    cin >> testes;
    while(testes--){
        cin >> n;
        vector<int> numeros(n);
        for (int i = 0; i < n; i++) {
            numeros[i] = i;
        }

        sort(numeros.begin(), numeros.end(), compare);    
        for (int i : numeros) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
