#include <iostream>
#include <vector>

using namespace std;

int encontrar_xi(int ni, int l, int r) {
    return max(l, min(r, ni));
}

int main() {
    int N, L, R;

    cin >> N >> L >> R;
    
    vector<int> numeros(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> numeros[i];
    }

    for (int i = 0; i < N; ++i) {
        int xi = encontrar_xi(numeros[i], L, R);
        cout << xi << " ";
    }

    return 0;
}
