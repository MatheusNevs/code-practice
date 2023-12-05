#include <bits/stdc++.h>
using namespace std;


int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> presos_disponiveis;
    int n, t, c;
    cin >> n >> t >> c;
    
    for (int i = 0; i < n; i++) {
        int prisioneiro;
        cin >> prisioneiro;
        if ( prisioneiro <= t)
            presos_disponiveis.push_back(prisioneiro);

    }
    return 0;
}