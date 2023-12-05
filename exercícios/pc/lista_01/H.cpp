#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,xc, yc, v, l = 0;
    cin >> n >> xc >> yc;

    for (int i = 1; i <= n ; i++) {
        int xi, yi, pi, distancia;
        cin >> xi >> yi >> pi;
        distancia = (abs(xi - xc) + abs(yi - yc))*2;
        if (l == 0){ 
        v = distancia + pi;
        l = i;
        } else {
            if ((distancia + pi) < v) {
                v = distancia + pi;
                l = i;
            }
        }

    }

    cout << v << " " << l;
    return 0;
}