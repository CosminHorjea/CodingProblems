#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
	int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
	{
		int nr = 0;
		unordered_map<int, int> seen1, seen2;
		for (int i : nums1)
		{
			for (int j : nums2)
			{
				seen1[i + j]++;
			}
		}
		for (int i : nums3)
		{
			for (int j : nums4)
			{
				seen2[i + j]++;
			}
		}
		for (auto iter : seen1)
		{
			if (seen2.find(0 - iter.first) != seen2.end())
			{
				nr += iter.second * seen2[0 - iter.first];
			}
		}
		return nr;
	}
};

int main()
{
	vector<int> nums1 = {-1, -1};
	vector<int> nums2 = {-1, 1};
	vector<int> nums3 = {-1, 1};
	vector<int> nums4 = {1, -1};
	Solution *p = new Solution();
	// assert(p->fourSumCount(nums1, nums2, nums3, nums4) == 6);
	cout << p->fourSumCount(nums1, nums2, nums3, nums4);
	// cout << "Should be good";
}