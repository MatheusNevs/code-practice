#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    vector<pair<int, int>> numeros(n);

    for (int i = 0; i < n; i++) {
        cin >> numeros[i].second;
        numeros[i].first = i;
    }

    sort(numeros.begin(), numeros.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    int prev = -1;
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (j > 0 && numeros[i].second == prev) {
        prev = numeros[i].second;
        numeros[i].second = j;
        }
        else {
            prev = numeros[i].second;
            j++;
            numeros[i].second = j;
        }
    }

    sort(numeros.begin(), numeros.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });

    for (int i = 0; i < n; i++) {
        cout << numeros[i].second << " ";
    }

    return 0;
}
