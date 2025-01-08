#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  vector<int> restaurants(n);
  for (int i = 0; i < n; i++)
  {
    cin >> restaurants[i];
  }

  sort(restaurants.begin(), restaurants.end());

  int q;
  cin >> q;
  for (int i = 0; i < q; i++)
  {
    int value;
    cin >> value;
    auto lower = upper_bound(restaurants.begin(), restaurants.end(), value);
    cout << (lower - restaurants.begin()) << endl;
  }

  return 0;
}