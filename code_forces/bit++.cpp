#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, x = 0;
  cin >> n;
  while (n--)
  {
    string operation;
    cin >> operation;
    if (*(operation.begin()) == '+' || *(operation.end() - 1) == '+')
    {
      x++;
      continue;
    }
    x--;
  }
  cout << x << endl;
  return 0;
}