#include <bits/stdc++.h>    
using namespace std;

int main () { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    set<int> numeros;

    for (int i = 0; i < n; i ++){
        int numero;
        cin >> numero;
        numeros.insert(numero);
    }

    vector<int> l_numeros(numeros.begin(), numeros.end());
    sort(l_numeros.begin(), l_numeros.end());
    
    
    cout << l_numeros[numeros.size() - 2];
    return 0;
}