#include <bits/stdc++.h>
using namespace std;

<<<<<<< HEAD

=======
>>>>>>> 7810f450969e270ceb1149589b0f809a7d9bef8c
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
<<<<<<< HEAD
    int n;
    cin >> n;

=======

    int n;
    cin >> n;
>>>>>>> 7810f450969e270ceb1149589b0f809a7d9bef8c
    vector<pair<int, int>> numeros(n);

    for (int i = 0; i < n; i++) {
        cin >> numeros[i].second;
        numeros[i].first = i;
    }

    sort(numeros.begin(), numeros.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

<<<<<<< HEAD
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
=======

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

>>>>>>> 7810f450969e270ceb1149589b0f809a7d9bef8c
