#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T, iter = 0;
const unsigned int M = 1000000007;

int mod(int a, int m = M)
{
  return (a % m + m) % m;
}

ll ord(char c)
{
  return c - 'a' + 1;
}

bool isPalindrome(string s)
{
  for (int i = 0; i < s.length() / 2; i++)
  {
    if (s[i] != s[s.length() - i - 1])
      return false;
  }
  return true;
}

bool isLesser(string s, string t)
{
  return s < t;
}

string reverseString(string s)
{
  reverse(s.begin(), s.end());
  return s;
}
void solve()
{
  ll N, K;
  string s;
  cin >> N >> K >> s;
  ll curr = 0, prev = 0;
  for (int i = 0; i <= ceil(N / 2.0) - 1; i++)
  {
    prev = curr;
    curr = ((K * (prev - 1)) % M + ord(s[i]));
    if (!prev)
    {
      curr = ord(s[i]);
      continue;
    }
  }
  string T;
  if (N % 2)
    T = s.substr(0, ceil(N / 2.0)) + reverseString(s.substr(0, ceil(N / 2.0) - 1));
  else
    T = s.substr(0, ceil(N / 2.0)) + reverseString(s.substr(0, ceil(N / 2.0)));
  // cout << "T: " << T << endl;
  if (isPalindrome(s) || !isLesser(T, s))
  {
    curr = mod(curr - 1);
  }
  cout << "Case #" << iter << ": " << curr % M << endl;
}

int main()
{
  cin >> T;
  while (iter++ < T)
    solve();
}