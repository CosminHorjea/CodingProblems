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
  ll N;
  cin >> N;
  cin.getline(0, 0);
  string s;
  vector<string> players;
  for (int i = 0; i < N; i++)
  {
    getline(cin, s);
    // cout << "i= " << i << " s= " << s << endl;
    players.push_back(s);
  }
  // for (auto s : players)
  //   cout << s << endl;
  int i = 0;
  while (i < N - 1)
  {
    int j = i + 1;
    if (players[j] < players[i])
    {
      swap(players[i], players[j]);
      ans++;
    }
    i++;
  }

  printf("Case #%lld: ", iter);
  cout << mod(ans) << endl;
}

int main()
{
  cin >> T;
  while (iter++ < T)
    solve();
}