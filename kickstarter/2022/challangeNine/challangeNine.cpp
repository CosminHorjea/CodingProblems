#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T, iter = 0;
const unsigned int M = 1000000007;

int mod(int a, int m = M) {
    return (a % m + m) % m;
}
void solve() {
    string ans = "";
    string num;
    cin >> num;
    ll sum = 0;
    for (char c : num) {
        sum += c - '0';
    }
    int i = 0;
    for (i = 0; i < 10; i++) {
        if ((sum + i) % 9 == 0) {
            break;
        }
    }
    if (i == 0) {
        num.insert(1, 1, '0');
    } else {
        int left = 0;
        while (num[left] - '0' <= i && left < num.size()) {
            left++;
        }
        num.insert(left, 1, (char)i + '0');
    }
    printf("Case #%lld: ", iter);
    cout << num << endl;
}

int main() {
    cin >> T;
    while (iter++ < T)
        solve();
}