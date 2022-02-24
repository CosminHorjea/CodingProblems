#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
	int removeCoveredIntervals(vector<vector<int>> &intervals)
	{
		int ans = intervals.size();

		sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b)
			 { if(a[0]==b[0]){
				 return a[1]<b[1];
			 }else{
				 return a[0]<b[0];
			 } });
		vector<int> curr = {-1, -1};
		for (vector<int> i : intervals)
		{
			cout << i[0] << i[1] << endl;
		}
		for (vector<int> iter : intervals)
		{
			if (iter[0] >= curr[0] && iter[1] <= curr[1])
			{
				ans--;
			}
			else
			{
				curr = iter;
			}
		}
		return ans;
	}
};

int main()
{
	Solution p;
	vector<vector<int>> nums = {{1, 2}, {1, 4}, {3, 4}};
	vector<vector<int>> nums2 = {{1, 4}, {3, 6}, {2, 8}};
	cout << p.removeCoveredIntervals(nums2);
}