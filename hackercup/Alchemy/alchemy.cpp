#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T, iter = 0;
const unsigned int M = 1000000007;

int mod(int a, int m = M)
{
  return (a % m + m) % m;
}
void solve()
{
  ll N, diff = 0;
  cin >> N;
  string s;
  cin >> s;
  for (char c : s)
  {
    if (c == 'A')
    {
      diff++;
    }
    else
    {
      diff--;
    }
  }

  char ans = abs(diff) > 1 ? 'N' : 'Y';

  printf("Case #%lld: ", iter);
  cout << ans << endl;
}

int main()
{
  cin >> T;
  while (iter++ < T)
    solve();
}