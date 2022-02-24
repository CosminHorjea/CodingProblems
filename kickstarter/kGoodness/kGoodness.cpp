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
  ll ans = 0;
  ll N, K, goodness = 0;
  string s;
  cin >> N >> K >> s;
  for (int i = 0; i < ceil(N / 2); i++)
  {
    if (s[i] != s[N - i - 1])
    {
      goodness++;
    }
  }
  ans = abs(K - goodness);
  printf("Case #%lld: ", iter);
  cout << ans << endl;
}

int main()
{
  cin >> T;
  while (iter++ < T)
    solve();
}