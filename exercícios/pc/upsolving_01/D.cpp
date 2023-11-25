#include <bits/stdc++.h>
using namespace std;

int mdc(int a, int b) {
    if (b == 0)
        return a;
    else 
        return mdc(b, a % b);
}

int mmc (int a, int b){
    return (a * b)/ mdc(a,b);
}


int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        for (int i = 1; i < x; i++) {
            int j = x - i;
            if (mmc(i,j) + mdc (i,j) == x) {
                cout << i << " " << j << "\n";
                break;
            }
        }
    }
    return 0;
}
