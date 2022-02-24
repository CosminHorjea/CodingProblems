#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
	int minimumDeviation(vector<int> &nums)
	{
		int N = nums.size();
		int minElem = INT_MAX;
		int ans = INT_MAX;
		priority_queue<int> pq;

		for (int i : nums)
		{
			if (i & 1)
			{
				i = i * 2;
			}
			pq.push(i);
			minElem = min(minElem, i);
		}
		while (!pq.empty())
		{
			int curr = pq.top();
			pq.pop();
			ans = min(ans, curr - minElem);
			cout << "CUrrent: " << curr << endl;
			cout << "ANs: " << ans << endl;
			cout << "min: " << minElem << endl;

			if (curr & 1)
				break;
			else
				pq.push(curr / 2);
			minElem = min(minElem, curr / 2);
		}
		return ans;
	}
};

int main()
{
	Solution p;
	vector<int> nums = {2, 10, 8};
	cout << p.minimumDeviation(nums);
}