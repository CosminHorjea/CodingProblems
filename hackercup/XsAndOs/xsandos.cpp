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
  int ans = 0, N;
  cin >> N;
  int globalMin = INT_MAX;
  set<pair<int, int>> used;
  char M[N][N];
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> M[i][j];
    }
  }
  for (int i = 0; i < N; i++)
  {
    int j = 0;
    pair<int, int> lastPoint;
    int count = 0;
    while ((j < N) && (M[i][j] != 'O'))
    {
      if (M[i][j] == '.')
      {
        lastPoint = {i, j};
        count++;
      }
      j++;
    }
    // cout << "Count= " << count << endl;
    if (j < N || count == 0)
    {
      continue;
    }
    if (globalMin > count)
    {
      globalMin = count;
      ans = 1;
    }
    else
    {
      if (globalMin == count)
      {
        ans++;
      }
    }
    if (count == 1)
      used.insert(lastPoint);
  }
  //print M
  // for (int i = 0; i < N; i++)
  // {
  //   for (int j = 0; j < N; j++)
  //   {
  //     cout << M[i][j];
  //   }
  //   cout << endl;
  // }
  //show used
  // for (auto it = used.begin(); it != used.end(); it++)
  // {
  //   cout << "(" << it->first << "," << it->second << ") ";
  // }
  for (int j = 0; j < N; j++)
  {
    int i = 0;
    int count = 0;
    pair<int, int> lastPoint;
    // cout << "i= " << i << " j= " << j << endl;
    while ((i < N) && (M[i][j] != 'O'))
    {
      // cout << "Enter" << endl;
      if (M[i][j] == '.')
      {
        lastPoint = {i, j};
        count++;
      }
      i++;
    }
    // cout << "Count= " << count << endl;
    if (i < N || count == 0)
    {
      continue;
    }

    if (globalMin > count)
    {
      globalMin = count;
      ans = 1;
    }
    else
    {
      if (globalMin == count && used.find(lastPoint) == used.end())
      {
        ans++;
      }
    }
    // if ((count == 1) && (used.find({i, j}) != used.end()))
    // {
    //   ans--;
    // }
  }

  printf("Case #%lld: ", iter);
  if (ans == 0)
  {
    cout << "Impossible" << endl;
  }
  else
  {
    cout << globalMin << " " << ans << endl;
  }
}

int main()
{
  cin >> T;
  while (iter++ < T)
    solve();
}