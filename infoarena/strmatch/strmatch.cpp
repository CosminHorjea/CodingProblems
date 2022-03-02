#include <bits/stdc++.h>

using namespace std;

ifstream f("strmatch.in");
ofstream g("strmatch.out");

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    string A, B;
    f >> A >> B;
    vector<int> ans;
    int n = B.size();

    vector<int> lps = prefix_function(A);
    int j = 0, i = 0;
    while (i < n) {
        if (B[i] == A[j]) {
            if (j == A.size() - 1) {
                if (ans.size() < 1000) {
                    ans.push_back(i - A.size() + 1);
                } else {
                    break;
                }
                j = lps[A.size() - 1];
            } else {
                j++;
            }
            i++;
        } else {
            if (j > 0) {
                j = lps[j];
            } else {
                i++;
            }
        }
    }
    g << ans.size() << endl;
    for (int i : ans) {
        g << i << " ";
    }
    f.close();
    g.close();
}