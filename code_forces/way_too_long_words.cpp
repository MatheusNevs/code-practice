#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  while (n--)
  {

    string m;
    cin >> m;
    int lenght = m.length();
    if (lenght > 10)
    {
      char first, last;
      first = *m.begin();
      last = *(m.end() - 1);
      cout << first << lenght - 2 << last << endl;
      continue;
    }

    cout << m << endl;
  }
  return 0;
}