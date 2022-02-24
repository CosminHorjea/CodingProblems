#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T, iter = 0;
const unsigned int M = 1000000007;

// verifies if a number is prime
bool isPrime(ll n)
{
  if (n == 2)
    return true;
  if (n % 2 == 0)
    return false;
  for (ll i = 3; i * i <= n; i += 2)
    if (n % i == 0)
      return false;
  return true;
}

ll isFirstPrime(ll n, ll Z)
{
  if (!isPrime(n))
    return 0;
  ll n2 = n;
  while (!isPrime(++n2))
  {
  }
  if (n * n2 <= Z)
    return n * n2;
  return 0;
}

int mod(int a, int m = M)
{
  return (a % m + m) % m;
}

void solve()
{
  ll ans = 0;
  ll Z;
  cin >> Z;
  ll k;
  printf("Case #%lld: ", iter);
  k = sqrt(Z) + 1;
  while (--k > 0)
  {
    ll ans = isFirstPrime(k, Z);
    if (ans)
    {
      cout << "k=" << k << endl;
      cout << ans << endl;
      break;
    }
  }
}

int main()
{
  cin >> T;
  while (iter++ < T)
    solve();
}