#include <bits/stdc++.h>
using namespace std;

int main () {
    unsigned long long raiz;
    unsigned long long n, raizAux, raizFinal;
    bool ehInteiro = false;

    cin >> n;
    raiz = pow( n, (double) 1/ (double) 3);
    raizAux = (int) raiz;
    for (unsigned long long i = raizAux; i < raizAux + 2; i++) {
        if ( i*i*i ==   n){   
            ehInteiro = true;
            raizFinal = i;
            break;
        }
    }

    if (ehInteiro)
        cout << raizFinal << "\n";
    else
        cout << -1 << "\n";
}

