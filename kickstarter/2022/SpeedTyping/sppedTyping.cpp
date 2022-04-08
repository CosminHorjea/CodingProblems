#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T, iter = 0;
const unsigned int M = 1000000007;

int mod(int a, int m = M) {
    return (a % m + m) % m;
}
void solve() {
    int ans = 0;
    string I, P;
    cin >> I >> P;
    int i = 0, j = 0;
    while (i < I.size()) {
        while (j < P.size() && (P[j] != I[i])) {
            ans++;
            j++;
        }
        if (j == P.size())
            break;
        i++;
        j++;
    }
    printf("Case #%lld: ", iter);
    if (i < I.size()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        ans += P.size() - j;
        cout << ans << endl;
    }
}

int main() {
    cin >> T;
    while (iter++ < T)
        solve();
}