#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  vector<int> classification(4, 0);
  cin >> n;

  while (n--)
  {
    int s;
    cin >> s;
    classification[s - 1]++;
  }

  int result = 0;

  result += classification[3];

  result += classification[2];

  classification[0] = classification[2] <= classification[0] ? classification[0] - classification[2] : 0;

  result += classification[1] / 2;

  classification[1] = classification[1] % 2;

  result += classification[1];

  classification[0] = classification[1] <= classification[0] / 2 ? classification[0] - classification[1] * 2 : 0;

  result += classification[0] % 4 == 0 ? (classification[0] / 4) : (classification[0] / 4) + 1;

  cout << result << endl;
  return 0;
}