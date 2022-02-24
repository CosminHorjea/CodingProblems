#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = int(1e9) + 5;
ll T, iter = 0;
const unsigned int M = 1000000007;

bool isVowel(char c)
{
  return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int mod(int a, int m = M)
{
  //please just use this, eben when you are only doing simple modulo, this gives good ans for negatives
  return (a % m + m) % m;
}
void solve()
{
  string vowels = "AEIOU";
  int ans = 0, vowNr = 0, conNr = 0, maxVow = 0, maxCon = 0, k;
  map<char, int> m;
  vector<vector<int>> dist;
  vector<char> v[26];
  string transition;
  string s;
  dist.assign(26, vector<int>(26, INF));
  for (int i = 0; i < 26; i++)
  {
    dist[i][i] = 0;
  }
  cin >> s;
  cin >> k;
  for (int i = 0; i < k; i++)
  {
    cin >> transition;
    dist[transition[0] - 'A'][transition[1] - 'A'] = 1;
  }
  //floyd warshall
  for (int i = 0; i < 26; i++)
  {
    for (int j = 0; j < 26; j++)
    {
      for (int k = 0; k < 26; k++)
      {
        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
      }
    }
  }

  //print dist
  // for (int i = 0; i < 26; i++)
  // {
  //   for (int j = 0; j < 26; j++)
  //   {
  //     cout << dist[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  ll best = INF;

  for (int i = 0; i < 26; i++)
  {
    ll sum = 0;
    for (auto ch : s)
    {
      sum += dist[ch - 'A'][i];
    }
    best = min(best, sum);
  }

  printf("Case #%lld: ", iter);
  cout << ((best < INF) ? best : -1) << endl;
}

int main()
{
  cin >> T;
  while (iter++ < T)
    solve();
}