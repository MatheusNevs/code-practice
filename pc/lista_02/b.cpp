#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, f, p, j = f, t = 0;
    queue<int> pesos;
    cin >> n >> f >> p;

    for (int i = 0; i < n; i++) {
        int peso;
        cin >> peso;
        pesos.push(peso);
    }

    while (!pesos.empty()) {
        int peso = pesos.front();
        pesos.pop();
        if ( j % f == 0) {
            if (peso > p){
                t += 10;
                peso -= 2;
                pesos.push(peso);
            }
            else if (peso <= p)
                t += 5;
        } else if (j % f != 0 ) {
            t++;
        }
            j++;
    }

    cout << t << "\n";
    return 0;
}