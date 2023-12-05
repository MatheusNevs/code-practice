#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> setMain;
    string numeroString;
    cin >> numeroString;
    for (char digito : numeroString) {
        setMain.insert(int (digito - '0'));
    }
    int numero = stoi(numeroString);
    bool found = false;
    while (found == false) {
        numero++;
        set<int> setAux;
        for (char digito : to_string(numero)) {
        setAux.insert(int (digito - '0'));
        if (setAux.size() == to_string(numero).size()){
            cout << numero;
            found = true;
        }
    }
    }
    return 0;
}