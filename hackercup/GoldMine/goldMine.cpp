#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T, iter = 0;
const unsigned int M = 1000000007;

int mod(int a, int m = M)
{
  //please just use this, eben when you are only doing simple modulo, this gives good ans for negatives
  return (a % m + m) % m;
}
void solve()
{
  ll ans = 0;
  int N;
  cin >> N;
  vector<int> G[N + 1];
  vector<int> C(N + 1);
  for (int i = 1; i <= N; i++)
  {
    cin >> C[i];
  }
  for (int i = 0; i < N - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  //dfs
  vector<bool> visited(N + 1, false);
  set<int> firsts(G[1].begin(), G[1].end());
  vector<int> dp(N + 1, 0);
  dp[1] = C[1];
  visited[1] = true;
  //bfs
  queue<int> q;
  vector<int> order;
  q.push(1);
  while (!q.empty())
  {
    int i = q.front();
    order.push_back(i);
    q.pop();
    int flag = 0;
    for (int j : G[i])
    {
      if (!visited[j])
      {
        flag = 1;
        visited[j] = true;
        dp[j] = dp[i] + C[j];
        q.push(j);
      }
    }
    if (!flag)
    {
      cout << "Terminal node: " << dp[i] << endl;
    }
  }
  ans = dp[order[N - 1]];
  if (firsts.size() > 1)
  {
    ans += dp[order[N - 2]];
    ans -= C[1];
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