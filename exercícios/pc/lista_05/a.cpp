#include <bits/stdc++.h>
using namespace std;

long long encontrar_xor_maximo(long long numero) {
    int numero_bits = 0;
    long long temp = numero;

    while (temp > 0) {
        temp >>= 1;
        numero_bits++;
    }

    bitset<64> binario(numero);
    string binario_str = binario.to_string();
    for (int i = 63; i >= 63 - numero_bits + 1; i--) {
        binario_str[i] = (binario_str[i] == '0') ? '1' : '0';
    }
    long long numero_invertido = bitset<64>(binario_str).to_ullong();
    return numero_invertido;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long numero_decimal;
    cin >> numero_decimal;
    
    long long resultado = encontrar_xor_maximo(numero_decimal);
    
    cout << numero_decimal << " " << resultado << "\n";

    return 0;
}
