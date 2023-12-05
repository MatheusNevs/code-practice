#include <bits/stdc++.h>
using namespace std;

void push(int presente, stack<pair<int, int>>& saco){
    if (!saco.empty())
        saco.push(make_pair(presente, max(presente, saco.top().second)));
    else
        saco.push(make_pair(presente, presente));
}

int main(){
    stack<pair<int,int>> saco;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char op;
        int  p;
        cin >> op >> p;
        if (op == 'A')
            push(p,saco);
        else if (op == 'V')
            if (saco.empty())
                cout << "0" << "\n";
            else
                cout << saco.top().second << "\n";
        else if (op == 'R')
            saco.pop();
    }
    return 0;
}