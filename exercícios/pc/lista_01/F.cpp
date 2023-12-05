#include <bits/stdc++.h>
using namespace std;


// mostrar soma de todos os inteiros que a soma
//  dos seus digitos seja maior ou igual a A e menor ou igual a B
int main() {
    int n, a, b, soma = 0;
    cin >> n >> a >> b;

    for (int i = 1; i <= n; i++) {
        int soma_digitos = 0;
        string str_numero = to_string(i);
        for (int j = 0; j < str_numero.size(); j++) {
            int digit = str_numero[j] - '0';
            soma_digitos += digit;
        }
        if ((soma_digitos >= a) && (soma_digitos <= b)) {
            soma += i;
        }
    }
    cout << soma << "\n";
    return 0;   
}