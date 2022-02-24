#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int T, iter = 0;
const unsigned int M = 1000000007;

int mod(ll a, ll m = M)
{
  return (a % m + m) % m;
}
void solve()
{
  ll ans = 0;
  ll option, p, q, n;
  printf("Case #%d: ", iter);
  cin >> option;
  if (option == 1)
  {
    cin >> n;
    p = 1;
    q = 1;
    stack<ll> bits;
    while (n > 1)
    {
      ll rem = n % 2;
      bits.push(rem);
      n /= 2;
    }
    while (bits.size() > 0)
    {
      ll rem = bits.top();
      bits.pop();
      if (rem == 1)
      {
        p = p + q;
      }
      else
      {
        q = q + p;
      }
    }
    cout << p << ' ' << q << endl;
  }
  else
  {
    n = 0;
    cin >> p >> q;
    ll pwer = 0;
    while (p != 1 || q != 1)
    {
      if (p > q)
      {
        p = p - q;
        n = ((ll)1 << pwer) | n;
      }
      else
      {
        q = q - p;
        // n = (0 << pwer) | n;
      }
      // cout << "N: " << n << endl;
      pwer++;
    }
    // cout << "POwer " << pwer << endl;
    n = ((ll)1 << (pwer)) | n;
    cout << n << endl;
  }
}

int main()
{
  cin >> T;
  while (iter++ < T)
    solve();
}