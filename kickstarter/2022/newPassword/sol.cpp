#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T, iter = 0;
const unsigned int M = 1000000007;

int mod(int a, int m = M) {
    return (a % m + m) % m;
}

const int LENGTH = 0;
const int UPPERCASE = 1;
const int LOWERCASE = 2;
const int DIGIT = 3;
const int SPECIAL_CHAR = 4;
const string specials = "#@*&";

void solve() {
    vector<int> checked(5);
    vector<char> fills = {' ', 'A', 'a', '0', '#'};
    string ans = "";
    int N;
    string currentPassword = "";
    cin >> N;
    cin >> currentPassword;
    ans += currentPassword;
    for (char c : currentPassword) {
        if (islower(c)) {
            checked[LOWERCASE] = 1;
        }
        if (isupper(c)) {
            checked[UPPERCASE] = 1;
        }
        if (isdigit(c)) {
            checked[DIGIT] = 1;
        }
        if (strchr(specials.c_str(), c)) {
            checked[SPECIAL_CHAR] = 1;
        }
    }
    for (int i = 1; i < 5; i++) {
        if (checked[i] == 0) {
            ans += fills[i];
        }
    }
    while (ans.size() < 7) {
        ans += '5';
    }

    printf("Case #%lld: ", iter);
    cout << ans << endl;
}

int main() {
    cin >> T;
    while (iter++ < T)
        solve();
}