#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, days = 0;
    vector<int> marathons;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int questions;
        cin >> questions;
        marathons.push_back(questions);
    }

    sort(marathons.begin(), marathons.end());

    for (int i = 0; i < n; i++) {
        if (marathons[i] >= days + 1) {
            days += 1;
        }
    }

    cout << days << "\n";
    return 0;
}
