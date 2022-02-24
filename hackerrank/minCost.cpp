#include <bits/stdc++.h>

using namespace std;

int getMinimumCost(int k, vector<int> c)
{
    sort(c.begin(), c.end());
    int kc = k;
    int ans = 0;
    int mult = 1;

    for (int i = c.size() - 1; i >= 0; i--)
    {
        ans += mult * c[i];
        kc--;
        if (kc == 0)
        {
            kc = k;
            mult++;
        }
    }
    return ans;
}

int maxMin(int k, vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int ans = INT_MAX;
    for (int i = 0; i <= arr.size() - k; i++)
    {
        // 1 2 4 7
        ans = min(ans, arr[i + k - 1] - arr[i]);
    }
    return ans;
}

int main()
{
    vector<int> flowers = {1, 4, 7, 2};
    int k = 2;
    cout << maxMin(k, flowers);

    return 0;
}