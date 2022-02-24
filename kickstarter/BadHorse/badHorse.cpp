#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T, iter = 0;
const unsigned int M = 1000000007;

void solve()
{
  string ans = "Yes";
  map<string, set<string>> m;
  ll N;
  cin >> N;
  for (ll i = 0; i < N; i++)
  {
    string s, p;
    cin >> s >> p;
    m[s].insert(p);
    m[p].insert(s);
  }
  queue<string> q;
  map<string, int> color;
  for (auto it = m.begin(); it != m.end(); it++)
  {
    color[it->first] = -1;
  }
  q.push(m.begin()->first);
  int team = 0;
  color[m.begin()->first] = 0;
  while (q.size())
  {
    team++;
    string s = q.front();
    q.pop();
    for (auto it = m[s].begin(); it != m[s].end(); it++)
    {
      if (*it == s)
        continue;
      if (color[*it] == color[s])
      {
        while (q.size())
          q.pop();
        ans = "No";
        break;
      }
      else if (color[*it] == -1)
      {
        color[*it] = 1 - color[s];
        q.push(*it);
      }
    }
  }
  printf("Case #%lld: %s\n", iter, ans.c_str());
}

int main()
{
  cin >> T;
  while (iter++ < T)
    solve();
}