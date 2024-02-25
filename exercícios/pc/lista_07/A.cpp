#include <bits/stdc++.h>
using namespace std;

int achar(vector<int>& numeros, const int alvo, int inicio, int fim) {
    if (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (numeros[meio] == alvo) {
            while (meio-1 >= 0 and numeros[meio-1] == alvo){
                    meio--;
                }
            return meio + 1;
        }
        else if (numeros[meio] > alvo)
            return achar(numeros, alvo, inicio, meio - 1);
        else
            return achar(numeros, alvo, meio + 1, fim);
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> numeros(n);
    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }

    sort(numeros.begin(), numeros.end());
    for (int i = 0; i < m; i++) {
        int consulta;
        cin >> consulta;
        cout << achar(numeros, consulta, 0, n - 1)<< " ";
    }

    return 0;
}
