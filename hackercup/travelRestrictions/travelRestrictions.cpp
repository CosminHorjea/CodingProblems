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
  ll N;
  cin >> N;
  vector<vector<char>> M(N, vector<char>(N, ' '));
  // cout << M.size() << endl;
  // cout << M[0].size() << endl;
  // return;
  vector<char> I(N), O(N);
  for (int i = 0; i < N; i++)
    cin >> I[i];
  for (int i = 0; i < N; i++)
    cin >> O[i];
  for (int i = 0; i < N; i++)
  {
    //pentru fiecare tara
    for (int j = i; j < N; j++)
    {
      if (j == i)
        M[i][j] = 'Y';
      else
      {
        if ((M[i][j - 1] == 'Y') && (O[j - 1] == 'Y') && (I[j] == 'Y'))
        {
          M[i][j] = 'Y';
        }
        else
        {
          M[i][j] = 'N';
        }
      }
    }
    for (int j = i - 1; j >= 0; j--)
    {
      if ((M[i][j + 1] == 'Y') && (O[j + 1] == 'Y') && (I[j] == 'Y'))
      {
        M[i][j] = 'Y';
      }
      else
      {
        M[i][j] = 'N';
      }
    }
  }
  printf("Case #%llu: \n", iter);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cout << M[i][j];
    }
    cout << endl;
  }
}

int main()
{
  cin >> T;
  while (iter++ < T)
    solve();
}