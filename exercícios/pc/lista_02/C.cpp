#include <bits/stdc++.h>
using namespace std;

int maiorPresente(stack<int> saco) {
    stack<int> sacoAux;
    int maior = 0;

    while (!saco.empty()) {
        int item = saco.top();
        if (item > maior)
            maior = item;
        saco.pop();
        sacoAux.push(item);
    }

    while (!saco.empty()) {
        int item = sacoAux.top();
        sacoAux.pop();
        saco.push(item);
    }

    return maior;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; 
    stack<int> saco;

    cin >> n;

    while (n--) {
        pair<char, int> op;
        cin >> op.first >> op.second;
        if (op.first == 'A') {
            saco.push(op.second);
        }
        if (op.first == 'V')
            cout << maiorPresente(saco) << "\n";            
        if (op.first == 'R')
            saco.pop();
    }

    return 0;
}