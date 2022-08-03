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
  long ans = 0;
  long N, Q;
  string s;
  map<int, map<char, int>> mem;
  cin >> N >> Q;
  cin >> s;
  mem[1] = {{s[0], 1}};
  for (int i = 1; i < N; i++)
  {
    mem[i + 1] = mem[i];
    mem[i + 1][s[i]]++;
  }

  for (int q = 0; q < Q; q++)
  {
    long l, r;
    cin >> l >> r;
    // cout << s.substr(l - 1, r - l + 1);
    if (r - l < 1)
    {
      // cout << ":da" << endl;
      ans++;
      continue;
    }
    map<char, int> m;
    if (l > 1)
    {
      for (pair<char, int> p : mem[r])
      {
        m[p.first] += p.second - mem[l - 1][p.first];
      }
    }
    else
    {
      m = mem[r];
    }
    int odds = 0;
    for (pair<char, int> p : m)
    {
      if (p.second % 2 == 1)
      {
        odds++;
      }
    }
    if (odds <= 1)
    {
      // cout << ":da" << endl;
      ans++;
    }
    else
    {
      // cout << ":nu" << endl;
    }
  }

  printf("Case #%lld: ", iter);
  cout << ans << endl;
}

int main()
{
  cin >> T;
  while (iter++ < T)
    solve();
}