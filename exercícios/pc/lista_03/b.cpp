#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    set<pair<char, char>> letra_trocadas;
    string t1, t2;
    int n;
    cin >> t1 >> t2 >> n;
    for (int i = 0; i <26; i++){
        if (t1[i] != t2[i]) {
            letra_trocadas.insert(t2[i], t1[i]);
        }
    }
    while (n--) {
        string frase, nova_frase = "";
        cin >> frase;
        for (char c : frase) {
            if ( c )
        }
    }
    return 0;
}