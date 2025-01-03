#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  while (n--)
  {
    int a, b;
    cin >> a >> b;
    int lowest = min(a, b);
    int greatest = max(a, b);
    int squareSide = max(2 * lowest, greatest);
    cout << pow(squareSide, 2) << endl;
  }
  return 0;
}