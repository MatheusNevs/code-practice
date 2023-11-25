#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> sequencia(n,0);
    vector<int> chave(m,0);


    for (int i = 0; i <n; i++){
        cin >> sequencia[i];
    }

    for (int i = 0; i <m; i++){
        cin >> chave[i];
    }

    for (int i = 0; i <= n - m; i++){
        for (int j = 0; j < m; j++){
            sequencia[i+j] = (sequencia[i+j] + chave[j])%c ;
        }
    }

    for (int i = 0; i <n; i++){
        cout << sequencia[i] << " ";
    }
    cout << "\n";

    return 0;

}