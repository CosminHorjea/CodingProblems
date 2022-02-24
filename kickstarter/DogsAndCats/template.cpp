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
  string ans = "YES";
  ll N, D, C, M;
  cin >> N >> D >> C >> M;
  string s;
  cin >> s;
  for (int i = 0; i < N; i++)
  {
    char currentAnimal = s[i];
    if (currentAnimal == 'D')
    {
      if (D == 0)
      {
        ans = "NO";
        break;
      }
      D -= 1;
      C += M;
    }
    else
    {
      if (C == 0)
      {
        for (int j = i; j < N; j++)
        {
          if (s[j] == 'D')
          {
            ans = "NO";
          }
        }
      }
      if (ans == "NO")
        break;
      C -= 1;
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