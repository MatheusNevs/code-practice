#include <bits/stdc++.h>
using namespace std;

string frase;
set<string> combinacoes;


void sub_strings(const int& nivel, const string& sub_str) {
    if (frase[nivel]) {
        sub_strings(nivel + 1, sub_str + frase[nivel]);
        sub_strings(nivel + 1, sub_str);
    } else {
        if (sub_str != "")
            combinacoes.insert(sub_str);
        return ;
    }
}


int main () {
    cin >> frase;
    int nivel = 0;
    sub_strings(0, "");

    for (string combinacao : combinacoes) {
        cout << combinacao << "\n";
    }
}