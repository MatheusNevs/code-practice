#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, q;
    cin >> n >> q;

    vector<long long> delta(n+1,0);

    while (q--){
        long long inicio, fim, adicional;
        cin >> inicio >> fim >> adicional;
        delta[inicio - 1] += adicional;
        delta[fim] -= adicional;

    }

    long long numero = 0;
    for ( int i = 0; i < n; i++) {
        numero = numero + delta[i];
        cout << numero << " ";
    }

    return 0;
}