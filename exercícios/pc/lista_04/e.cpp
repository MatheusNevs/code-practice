#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, q, soma = 0;
    cin >> n >> q;
    vector<int> lista(n);
    vector<int> delta_op(n + 1,0);
    vector<int> operacoes(n);

    for (long long i = 0; i < n; i++){
        cin >> lista[i];
    }

    while (q--){
        long long l, r;
        cin >> l >> r;
        delta_op[l - 1] += 1;
        delta_op[r] -= 1;
    }

    long long op = 0;
    for (long long i = 0; i < n; i++){
        op = op + delta_op[i];
        operacoes[i] = op;
    }

    sort(lista.begin(), lista.end());
    sort(operacoes.begin(), operacoes.end());

    for (long long i = 0; i <= n; i++){
        soma = soma + (operacoes[n-i]*lista[n-i]);
    }

    cout << soma << "\n";
    return 0;
}