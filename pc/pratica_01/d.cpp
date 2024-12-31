#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> cores(52, vector<char>(52));
vector<vector<bool>> visitados(52, vector<bool>(52, false));
bool cicloEncontrado;
int linhas, colunas;

void dfs(int i, int j, int iAnterior, int jAnterior, char cor) {
    if (i < 0 || j < 0 || i >= linhas || j >= colunas)
        return;

    if (cores[i][j] != cor){
        return;
    }

    if (visitados[i][j]) {
        cicloEncontrado = true;
        return;
    }

    visitados[i][j] = true;

    if (i + 1 != iAnterior || j != jAnterior)
        dfs(i + 1, j, i, j, cor);

    if (i != iAnterior || j + 1 != jAnterior)
        dfs(i, j + 1, i, j, cor);

    if (i - 1 != iAnterior || j != jAnterior)
        dfs(i - 1, j, i, j, cor);

    if (i != iAnterior || j - 1 != jAnterior)
        dfs(i, j - 1, i, j, cor);
}

bool temCiclo() {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (!visitados[i][j]) {
                dfs(i, j, -1, -1, cores[i][j]);
                if (cicloEncontrado)
                    return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> linhas >> colunas;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cin >> cores[i][j];
        }
    }

    bool resultado = temCiclo();

    if (resultado)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
