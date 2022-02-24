#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T, iter = 0;
const unsigned int M = 1000000007;

struct tree
{
  int pos, height;
};

int mod(int a, int m = M)
{
  //please just use this, eben when you are only doing simple modulo, this gives good ans for negatives
  return (a % m + m) % m;
}
void solve()
{
  int ans = 0;
  ll N;
  cin >> N;
  vector<tree> t(N);
  for (int i = 0; i < N; i++)
  {
    cin >> t[i].pos >> t[i].height;
  }
  map<int, int> rightFall;
  map<int, int> leftFall;
  //sort P and H
  sort(t.begin(), t.end(), [](tree a, tree b)
       { return a.pos < b.pos; });

  for (int i = 0; i < N; i++)
  {
    rightFall[t[i].pos + t[i].height] = max(t[i].height + rightFall[t[i].pos], rightFall[t[i].pos + t[i].height]);
    ans = max(ans, rightFall[t[i].pos + t[i].height]);
  }

  sort(t.begin(), t.end(), [](tree a, tree b)
       { return a.pos > b.pos; });
  ;
  for (int i = 0; i < N; i++)
  {
    leftFall[t[i].pos - t[i].height] = max(t[i].height + leftFall[t[i].pos], leftFall[t[i].pos - t[i].height]);
    ans = max(ans, leftFall[t[i].pos - t[i].height]);
  }

  // print maps
  // cout << "Right" << endl;
  // for (auto it = rightFall.begin(); it != rightFall.end(); it++)
  // {
  //   cout << it->first << " " << it->second << endl;
  // }
  // cout << "Left " << endl;
  // for (auto it = leftFall.begin(); it != leftFall.end(); it++)
  // {
  //   cout << it->first << " " << it->second << endl;
  // }

  for (auto it : rightFall)
  {
    if (it.second && leftFall[it.first])
      ans = max(ans, it.second + leftFall[it.first]);
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