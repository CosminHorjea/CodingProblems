#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T, iter = 0;
const unsigned int M = 1000000007;

int mod(int a, int m = M)
{
  return (a % m + m) % m;
}

ll calculate(ll k, ll n)
{
  if (k <= 0)
    return 0;
  // cout << "calculate(" << k << ", " << n << ")" << endl;
  ll res = n * k + n * (n - 1) / 2;
  // cout << res << endl;
  return res;
}

void solve()
{
  ll G, ans = 0;
  cin >> G;
  int div = 1;
  while (++div <= sqrt(G) * 2)
  {
    ll res = G / div;
    if (calculate(res - div / 2 + 1 - div % 2, div) == G)
    {
      // cout << div << endl;
      // cout << div << endl;
      ans++;
    }
  }

  if (G <= 2)
    ans = 0;
  cout << "Case #" << iter << ": " << ans + 1 << endl;
}

int main()
{
  cin >> T;
  while (iter++ < T)
    solve();
}