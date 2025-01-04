#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string message, result;
  cin >> message;

  string vowels = "AaOoYyEeUuIi";

  for (size_t i = 0; i < message.size(); ++i)
  {
    size_t pos = vowels.find(message[i]);
    if (pos == string::npos)
    {
      result += '.';
      result += tolower(message[i]);
    }
  }
  cout << result << endl;

  return 0;
}