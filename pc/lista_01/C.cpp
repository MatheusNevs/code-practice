#include <bits/stdc++.h>

using namespace std;

int main () {
    int inteiro, moedas, resto;

    cin >> inteiro >> moedas;
    resto = inteiro % 500;
    if (resto <= moedas) {
        cout << "Sim" << "\n";
    } else {
        cout << "Nao" << "\n";
    }

    return 0;
}