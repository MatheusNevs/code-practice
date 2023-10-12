#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, menorb, maiorb = 0, menorh, maiorh = 0;
    bool um = false;
    cin >> n >> m;
    menorb = m;
    menorh = n;

    for (int i = 0; i < n; i++) {
        string linha;
        cin >> linha;
        for (int j = 0; j < m; j++) {
            if (linha[j] == '1') {
                um = true;
                if (j < menorb){
                menorb = j;
                }
                if (j > maiorb){
                    maiorb = j;
                }
                if (i > maiorh) {
                    maiorh = i;
                }
                if (i < menorh){
                    menorh = i;
                }
            }
        }
    }
    if (um)
        cout << (maiorb - menorb + 1) << "x" << (maiorh - menorh + 1) << "\n";
    else
    cout << '0' << 'x' << '0' << '\n';
    return 0;
    }
    

