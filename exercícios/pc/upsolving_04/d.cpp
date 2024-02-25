#include <bits/stdc++.h>
using namespace std;

int dividir_por_2(set<int>& numeros) {
    int operacoes = 0;
    while (!numeros.empty()) {
        int maiorElemento = *(numeros.rbegin());
        numeros.erase(maiorElemento);
        maiorElemento = maiorElemento / 2;
        operacoes++;
        if (maiorElemento % 2 == 0)
            numeros.insert(maiorElemento);
    }
    return operacoes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, ans;
    cin >> t;
    while (t--) {
        cin >> n;
        set<int> numeros;
        for (int i = 0; i < n; i++) {
            int numero;
            cin >> numero;
            if (numero % 2 == 0)
                numeros.insert(numero);
        }
        ans = dividir_por_2(numeros);
        cout << ans << "\n";
    }

    return 0;
}
