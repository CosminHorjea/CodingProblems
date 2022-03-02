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
    int N, M, S;
    vector<int> ans;
    cin >> N;
    vector<string> names(N + 1);
    for (int i = 1; i <= N; i++)
    {
        string s;
        cin >> s;
        names.push_back(s);
    }
    cin >> M;
    unordered_map<int, pair<int, int>> travel;
    for (int i = 1; i <= M; i++)
    {
        int a, b, t;
        cin >> a >> b >> t;
        travel[a] = {b, t};
    }
    cin >> S;
    vector<pair<int, int>> paths;
    for (int i = 1; i < S; i++)
    {
        int p, q;
        cin >> p >> q;
        paths.push_back({p, q});
    }

    printf("Case #%lld: ", iter);
    // cout << ans << endl;
}

int main()
{
    cin >> T;
    while (iter++ < T)
        solve();
}