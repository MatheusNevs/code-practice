#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, t;
    cin >> n >> t;
    vector<int> an(n, 0);
    vector<bool> visiteds(n + 1, false);

    for (int i = 1; i < n; i++) {
        cin >> an[i];
    }

    int index = 1;
    while (index < n) {
        visiteds[index] = true;
        index = index + an[index];
    }
    visiteds[index] = true;

    if (visiteds[t])
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
