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
  printf("Case #%lld: ", iter);
  string s;
  ll ans = 0, N;
  cin >> N;
  cin >> s;
  ll currLength = 1, maxLength = 0;
  cout << currLength << " ";
  for (int i = 1; i < N; i++)
  {
    if (s[i] > s[i - 1])
    {
      currLength++;
      maxLength = max(maxLength, currLength);
    }
    else
    {
      currLength = 1;
    }
    cout << currLength << " ";
  }
  cout << endl;
}

int main()
{
  cin >> T;
  while (iter++ < T)
    solve();
}