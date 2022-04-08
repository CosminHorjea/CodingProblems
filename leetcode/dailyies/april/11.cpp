#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            int curr = min(height[left], height[right]) * (right - left);
            ans = max(ans, curr);

            if (height[left] > height[right]) {
                right--;
            } else {
                left++;
            }
        }
        return ans;
    }
};