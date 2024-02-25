#include <bits/stdc++.h>
using namespace std;

long long achar(vector<long long>& numeros, const long long alvo, long long inicio, long long fim) {
    if (inicio <= fim) {
        long long meio = inicio + (fim - inicio) / 2;

        if (numeros[meio] == alvo) {
            while (meio-1 >= 0 and numeros[meio-1] == alvo){
                    meio--;
                }
            return meio + 1;
        }
        else if (numeros[meio] > alvo)
            return achar(numeros, alvo, inicio, meio - 1);
        else
            return achar(numeros, alvo, meio + 1, fim);
    }

    return -1;
}

void solve(vector<long long>& numeros, const long long dinheiro) {
    auto atual = numeros.begin();
    long long livro1Ant = 0, livro2Ant = 0, dif = 100000;
    while (atual - numeros.begin() < numeros.size() - 1 and *atual < dinheiro) {
        long long livro1 = *atual;
        auto livro2 = find(atual + 1, numeros.end(), dinheiro-livro1);
        if ( livro2 != numeros.end() and *livro2 - livro1 < dif) {
            dif = *livro2 - livro1;
            livro1Ant = livro1;
            livro2Ant = *livro2;
        }
        atual++;
    }

    cout << livro1Ant << " " << livro2Ant << "\n";
    return ;
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, m;
    cin >> n >> m;
    vector<long long> numeros(n);
    
    for ( long long i = 0; i < n; i++){
        cin >> numeros[i];
    }

    sort(numeros.begin(), numeros.end());
    solve(numeros, m); 

    return 0;
}