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
    ll ans;
    ll N;
    cin >> N;
    ans = N / 5 + (N % 5 != 0);
    printf("Case #%lld: ", iter);
    cout << ans << endl;
}

int main()
{
    cin >> T;
    while (iter++ < T)
        solve();
}