#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long double n, m, a, result = 0;
  cin >> n >> m >> a;
  long double chosen, notChosen;

  long double result1 = ceil(n / a);
  result += result1;
  long double result2 = ceil(m / a);
  result *= result2;

  cout << fixed << setprecision(0) << result << endl;
  return 0;
}