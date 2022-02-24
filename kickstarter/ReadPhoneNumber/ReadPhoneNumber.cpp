#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T, iter = 0;
const unsigned int M = 1000000007;

int mod(int a, int m = M)
{
  //please just use this, even when you are only doing simple modulo, this gives good ans for negatives
  return (a % m + m) % m;
}

map<int, string> multiples = {
    {1, ""},
    {2, "double"},
    {3, "triple"},
    {4, "quadruple"},
    {5, "quintuple"},
    {6, "sextuple"},
    {7, "septuple"},
    {8, "octuple"},
    {9, "nonuple"},
    {10, "decuple"},
};
map<int, string> digit = {
    {0, "zero"},
    {1, "one"},
    {2, "two"},
    {3, "three"},
    {4, "four"},
    {5, "five"},
    {6, "six"},
    {7, "seven"},
    {8, "eight"},
    {9, "nine"},
};

void solve()
{
  string phoneNumber, groups;
  cin >> phoneNumber;
  cin >> groups;
  int i = 0, j = 1;
  int k = 0, l = 0;
  printf("Case #%lld: ", iter);
  while (j < groups.length() + 1)
  {
    while (groups[j] != '-' && j < groups.length())
    {
      j++;
    }
    int currentGroup = stoi(groups.substr(i, j - i));
    // cout << "|" << currentGroup << "|";
    int limit = k + currentGroup;
    while (k < limit)
    {
      while (phoneNumber[k] == phoneNumber[l])
      {
        if (l + 1 > limit)
          break;
        l++;
      }
      if ((l - k > 1) && (l - k <= 10))
        cout << multiples[l - k] << " ";
      if (l - k > 10)
      {
        for (int iter = k; iter < l; iter++)
        {
          cout << digit[phoneNumber[iter] - '0'] << " ";
        }
      }
      else
      {
        cout << digit[phoneNumber[k] - '0'] << " ";
      }
      k = l;
    }

    i = j + 1;
    j += 2;
  }
  cout << endl;
}

int main()
{
  cin >> T;
  while (iter++ < T)
    solve();
}