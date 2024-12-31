#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    set<int> estoque;

    int q;
    cin >> q;
    while (q--){
        int t, m;
        cin >> t >> m;
        if (t == 1) {
            estoque.insert(m);
        } if ( t == 2){
            auto achado = estoque.find(m);
            if (achado != estoque.end())
                cout << "Sim\n";
            else
                cout << "Nao\n";
        }   
    }
    return 0;
}