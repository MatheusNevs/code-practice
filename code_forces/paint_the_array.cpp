#include <bits/stdc++.h>
using namespace std;

#include <cmath>

long long calcularMDC(long long a, long long b)
{
  if (a == 0)
    return b;
  return calcularMDC(b % a, a);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long t;
  cin >> t;

  while (t--)
  {
    long long n;
    cin >> n;

    vector<long long> array(n);
    for (long long i = 0; i < n; i++)
    {
      cin >> array[i];
    }

    long long mdc1 = 0, mdc2 = 0;
    for (long long i = 0; i < n; i++)
    {
      if (i % 2 == 0)
      {
        mdc1 = calcularMDC(mdc1, array[i]);
      }
      else
      {
        mdc2 = calcularMDC(mdc2, array[i]);
      }
    }

    bool success = false;
    if (mdc1 > 1)
    {
      success = true;
      for (long long i = 1; i < n; i += 2)
      {
        if (array[i] % mdc1 == 0)
        {
          success = false;
          break;
        }
      }
      if (success)
      {
        cout << mdc1 << endl;
        continue;
      }
    }

    success = false;
    if (mdc2 > 1)
    {
      success = true;
      for (long long i = 0; i < n; i += 2)
      {
        if (array[i] % mdc2 == 0)
        {
          success = false;
          break;
        }
      }
      if (success)
      {
        cout << mdc2 << endl;
        continue;
      }
    }

    cout << 0 << endl;
  }

  return 0;
}
