#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, l, s = 0;
    cin >> n >> l;

    while (n--){
        int nota;
        cin >> nota;
        if (nota >= l){
            s++;
        }
    }

    cout << s << "\n";
    return 0;
}