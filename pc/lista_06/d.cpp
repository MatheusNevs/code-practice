#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k, paredes = 0, celulas_vazias;
    char caractere;
    queue<pair<int, int>> fila;
    cin >> n >> m >> k;
    vector<vector<bool>> visitados(n, vector<bool>(m,false));
    vector<vector<char>> campo(n, vector<char>(m, '0'));

    for (int i =0; i<n; i++){
        for (int j =0; j<m; j++){
            char digito;
            cin >> digito;
            if (digito == '#') {
                paredes++;
                campo[i][j] = '#';
            }
        }
    }
    celulas_vazias = (n*m) - paredes - k;

    for (int i =0; i<n; i++){
        for (int j =0; j<m; j++){
            if (campo[i][j] != '#' and !visitados[i][j]) {
                fila.push(make_pair(i,j));
                visitados[i][j] = true;
                while(!fila.empty()) {
                    int linha, coluna;
                    tie(linha, coluna) = fila.front();
                    fila.pop();
                    caractere = (celulas_vazias > 0)? '.': 'X';
                    celulas_vazias--;
                    campo[linha][coluna] = caractere;
                    if (linha + 1 < n and !visitados[linha+1][coluna] and campo[linha+1][coluna] != '#'){
                        visitados[linha+1][coluna] = true;
                        fila.push(make_pair(linha+1, coluna));
                    }
                    if (linha - 1 >= 0 and !visitados[linha-1][coluna] and campo[linha-1][coluna] != '#') {
                        visitados[linha-1][coluna] = true;
                        fila.push(make_pair(linha-1, coluna));
                    }
                    if (coluna + 1 < m and !visitados[linha][coluna + 1] and campo[linha][coluna+1] != '#'){
                        visitados[linha][coluna + 1] = true;
                        fila.push(make_pair(linha, coluna + 1));
                    }
                    if (coluna - 1 >= 0 and !visitados[linha][coluna - 1] and campo[linha][coluna-1] != '#') {
                        visitados[linha][coluna - 1] = true;
                        fila.push(make_pair(linha, coluna - 1));
                    }
                }
            }
        }
    }


    for (int i =0; i<n; i++){
        for (int j =0; j<m; j++){
            cout << campo[i][j];
        }
        cout << "\n";
    }
    return 0;
}
