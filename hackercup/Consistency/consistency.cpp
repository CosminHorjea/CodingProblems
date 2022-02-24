#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T, iter = 0;
const unsigned int M = 1000000007;

bool isVowel(char c)
{
  return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int mod(int a, int m = M)
{
  //please just use this, eben when you are only doing simple modulo, this gives good ans for negatives
  return (a % m + m) % m;
}
void solve()
{
  string vowels = "AEIOU";
  int ans = 0, vowNr = 0, conNr = 0, maxVow = 0, maxCon = 0;
  map<char, int> m;
  string s;

  cin >> s;
  for (char c : s)
  {
    m[c]++;
    if (isVowel(c))
    {
      vowNr++;
      maxVow = max(maxVow, m[c]);
    }
    else
    {
      conNr++;
      maxCon = max(maxCon, m[c]);
    }
  }

  // print variables
  // cout << "vowNr: " << vowNr << endl;
  // cout << "conNr: " << conNr << endl;
  // cout << "maxVow: " << maxVow << endl;
  // cout << "maxCon: " << maxCon << endl;

  ans = conNr - maxCon + vowNr - maxVow;
  // cout << "Ans " << ans << endl;
  ans += min(conNr + (vowNr - maxVow) - (conNr - maxCon), vowNr + (conNr - maxCon) - (vowNr - maxVow));

  printf("Case #%lld: ", iter);
  cout << ans << endl;
}

int main()
{
  cin >> T;
  while (iter++ < T)
    solve();
}