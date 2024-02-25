#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string numero_str, numeros_subtraidos = "";
    cin >> numero_str;
    int numero, ans = 0;
    numero = stoi(numero_str);

    while (numero > 0) {
        int subtrair;
        string subtrair_str = ""
        for ( char caractere : numero_str) {
            int char_numerico = caractere - '0';
            subtrair_str += (char_numerico == 0)? '0' : '1';
        }
        subtrair = stoi(subtrair_str);
        numero -= subtrair;
        numeros_subtraidos += subtrair_str + " ";
        ans++;
        numero_str = to_string(numero);
    }

    cout << ans << "\n";
    cout << numeros_subtraidos << "\n";
    return 0
}