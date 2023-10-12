#include <bits/stdc++.h>

using namespace std;

int main () {
    int numeros, numero, soma = 0, i = 0, dinheiro_distribuido;
    vector<int> arr;
    
    cin >> numeros;
    cin.ignore();

    string linha;
    getline(cin, linha);
    stringstream ss(linha);

    while (ss >> numero) {
        arr.push_back(numero);
        soma += arr[i];
        i++;
    }

    sort(arr.begin(), arr.end());
    dinheiro_distribuido = (arr.back())*numeros - soma;
    cout << dinheiro_distribuido << "\n";
    return 0;
}