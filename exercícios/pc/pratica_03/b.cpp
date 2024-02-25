#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string frase;
    bool trocado = false;
    cin >> frase;
    int qt = frase.size(), ocorrencias = 0;

    for (int i = 1; i < qt; i++){
        if (frase[i] == 'V') {
            if (frase[i-1] == 'V' and !trocado){
                frase[i] = 'K';
                trocado = true;
                ocorrencias++;
            }
        } else {

        }
    }
    return 0;
}