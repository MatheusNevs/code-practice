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


    int ant = numeros[0].second;
    numeros[0].second = 1;

    for (int i = 1; i < n; i++) {
        if (numeros[i].second == ant) {
            numeros[i].second = numeros[i-1].second;
        } else {
            ant = numeros[i].second;
            numeros[i].second = i+1;
        }
    }

    sort(numeros.begin(), numeros.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.first < b.first;
    });

    for (int i = 0; i < n; i++){
        cout << numeros[i].second << " ";
    }
    cout << "\n";

    return 0;
}

