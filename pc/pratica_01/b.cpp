#include <bits/stdc++.h>
using namespace std;

int contar_ocorrencias(const string frase, const string caso) { 
    int contador = 0;

    for (size_t i = 0; i < frase.length(); ++i) {
        if (frase.substr(i, caso.length()) == caso) {
            ++contador;
        }
    }

    return contador;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string frase;
    cin >> frase;
    int ocorrencias = contar_ocorrencias(frase, "VK");
    for (int i = 0; i < frase.size(); i++){
        string aux = frase;
        if (frase[i] == 'V')
            aux[i] = 'K';
        if (frase[i] == 'K')
            aux[i] = 'V';
        int aux_ocorrencias = contar_ocorrencias(aux, "VK");
        if (aux_ocorrencias > ocorrencias)
            ocorrencias = aux_ocorrencias; 
    }

    cout << ocorrencias << "\n";
    return 0;
}