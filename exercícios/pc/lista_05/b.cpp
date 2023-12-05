#include <bits/stdc++.h>
using namespace std;

int main () {
    int a,b,c, posicao = 0;
    cin >> a;
    b = a ^ 0;
    while (b){
        posicao++;
        b >>=1;
    }

    c = pow(2, posicao) - 1;
    cout << a << " " << c - a;

}