#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int mod = 10e+7;
    int threeSumMulti(vector<int>& arr, int target) {
        long ans = 0;
        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++) {
            int T = target - arr[i];
            int j = i + 1, k = arr.size() - 1;
            while (j < k) {
                if (arr[j] + arr[k] < T) {
                    j++;
                } else if (arr[j] + arr[j] > T) {
                    k--;
                } else if (arr[j] != arr[k]) {
                    int left = 1;
                    int right = 1;
                    while (j + 1 < k && arr[j] == arr[j + 1]) {
                        left++;
                        j++;
                    }
                    while (k - 1 > j && arr[k] == arr[k - 1]) {
                        right++;
                        k--;
                    }

                    ans += left * right;
                    ans %= mod;
                    j++;
                    k--;
                } else {
                    ans += (k - j - 1) * (k - j) / 2;
                    ans %= mod;
                    break;
                }
            }
        }
        return (int)ans;
    }
};