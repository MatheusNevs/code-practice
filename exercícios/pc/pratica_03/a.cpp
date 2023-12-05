#include <bits/stdc++.h>
using namespace std;

void sequencias_distintas(const string& s, set<string>& combinacoes) {

    for (size_t i = 0; i < s.length(); ++i) {
        for (int j = i; j < s.length(); ++j) {
            combinacoes.insert(s.substr(i, j - i + 1));
        }
    }
    return ;
}

int main() {
    string s;
    cin >> s;

    set<string> sequencias;
    vector<char> s_sem_repeticao;

    for ( int i = 0; i < s.size(); i++){

        auto it = find(s_sem_repeticao.begin(), s_sem_repeticao.end(), s[i]);
        if (it == s_sem_repeticao.end()) {
            s_sem_repeticao.push_back(s[i]);
        }
    }

    string s_sem_repeticao_str(s_sem_repeticao.begin(), s_sem_repeticao.end());
    sequencias_distintas(s, sequencias);
    sequencias_distintas(s_sem_repeticao_str, sequencias);

    for (const auto& sequencia : sequencias) {
        cout << sequencia << endl;
    }

    return 0;
}
