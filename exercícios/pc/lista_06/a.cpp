#include <bits/stdc++.h>
using namespace std;



int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        char letra = (i%2) ? 'W' : 'B';
        for (int j = 0; j < m; j++){
            char celula;
            cin >> celula;
            if (celula == '-'){
                cout << '-';
            } else cout << letra;

            letra = (letra == 'B') ? 'W' : 'B';
        }
        cout << "\n";
    }

    return 0;
}