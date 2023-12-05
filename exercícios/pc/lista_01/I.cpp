#include <bits/stdc++.h>
using namespace std;

int main () {
    int n,m, nnovo = n, mnovo = m;
    vector<string> matriz;
    for (int i = 0; i < n; i++) {
        string linha;
        bool found = false;
        cin >> linha;
        for (int j = 0; j < m; j++) {
            if (linha[j] == '1') {
                found = true;
                break;
            }
        }
        if (found == true){
            matriz.push_back(linha);
        } else {
            nnovo -= 1;
        }
    }

    for (int i = 0; i < m; i++) {
        bool found = false;
        for (int j = 0; j < m; j++) {
            if (matriz[i][j] == '1')
                found = true;
        }
        if (found == false)
        mnovo -= 1;
    }

    cout << nnovo << "x" << mnovo;
    return 0;
    }


