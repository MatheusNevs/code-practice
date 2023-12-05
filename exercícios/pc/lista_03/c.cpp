#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, t, c, disponiveis = 0, possibilidades = 0;
    cin >> n >> t >> c;

    for ( int i = 0; i < n; i++){
        int preso;
        cin >> preso;
        if (preso <= t) 
            disponiveis++;
        else {
            if (disponiveis >= c)
                possibilidades += disponiveis - c + 1;
            disponiveis = 0;
        }
        
    }
            
    if (disponiveis >= c) 
        possibilidades += disponiveis - c + 1;
    cout <<  possibilidades << "\n"; 
    return 0;
}