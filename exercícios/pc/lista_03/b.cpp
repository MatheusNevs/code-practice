#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string t1, t2;
    int testes;
    map<char, char> letras_trocadas;
    cin >> t1 >> t2 >> testes;

    for ( int i = 0; i < 26; i++){
        if (t2[i] != t1[i]) {
            letras_trocadas[t1[i]] = t2[i];
        }
    }
    while (testes--) {
        string frase, frase_nova = "";
        cin >> frase;
        for ( char c : frase ){
            auto it = letras_trocadas.find(c);
            if (it != letras_trocadas.end()) {
                char valor = it->second;
                frase_nova += valor;
            }else {
                auto it = letras_trocadas.find(tolower(c));
                if (it != letras_trocadas.end()) {
                    char valor = toupper(it->second);
                    frase_nova += valor;
                } else {
                    frase_nova += c;
                }
            }
        }
    cout << frase_nova << "\n";
    }

    return 0;
}