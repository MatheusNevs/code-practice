#include <bits/stdc++.h>
using namespace std;

queue<pair<int, int>> vertices;
vector<bool> visitados(10002, false);

int menor_clicks(const int n, const int m) {
    vertices.push(make_pair(n, 0));
    visitados[n] = true;
    
    while (!vertices.empty()) {
        int number, clicks;
        tie(number, clicks) = vertices.front();
        vertices.pop();

        if (number == m) {
            return clicks;
        }

        if (number - 1 > 0 and !visitados[number - 1]) {
            visitados[number - 1] = true;
            vertices.push(make_pair(number - 1, clicks + 1));
        }
        if (number * 2 <= 10000 and !visitados[number * 2]) {
            visitados[number * 2] = true;
            vertices.push(make_pair(number * 2, clicks + 1));
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    int result = menor_clicks(n, m);
    
    cout << result << "\n";

    return 0;
}
