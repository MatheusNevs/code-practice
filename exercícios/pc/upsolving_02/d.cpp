#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> tamanduas;
    int x, y, z, m, n, qtTamanduas = 1;
    string ordem;

    cin >> x >> y >> z >> m >> n;
    cin >> ordem;

    tamanduas.push_back(m);

    for (char cupin : ordem) {
        int tamanho;
        if (cupin == 'F')
            tamanho = x;
        if (cupin == 'A')
            tamanho = y;
        if (cupin == 'R')
            tamanho = z;
        for (int i = 0; i < tamanduas.size(); i++){
            if (tamanduas[i] - tamanho >= 0) {
                tamanduas[i] -= tamanho;
                break;
            } else {
                if (i == tamanduas.size() - 1){
                    int podeComer = m - tamanho;
                    tamanduas.push_back(podeComer);
                    qtTamanduas++;
                    break;
                }
            }

        }
        }
    cout << qtTamanduas << "\n";
    }
