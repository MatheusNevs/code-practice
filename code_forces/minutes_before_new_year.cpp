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
    int hour, minutes;
    cin >> hour >> minutes;
    cout << (23 - hour) * 60 + (60 - minutes) << endl;
  }
  return 0;
}