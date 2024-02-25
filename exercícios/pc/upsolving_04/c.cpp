#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--){
    int n;
    cin >> n;
    vector<long long> numeros(n);
    
    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }
    sort(numeros.begin(), numeros.end());
    for (int i = n -2; i >= 0; i--) {
        numeros[i] = numeros[i] & numeros[i + 1];
    }
    
    cout << numeros[0] << "\n";
    
    } 
    return 0;
}