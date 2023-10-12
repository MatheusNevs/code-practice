#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, G, F, C, S;
    cin >>  N >> G >> F >> C;
    S = C;
    if (G < F) {
        S += G;
    }
    else {
        S+= F;
    }

    if (S <= N){ 
    cout << S << "\n";
    } else {
        cout << N << "\n";
    }
    return 0;
}