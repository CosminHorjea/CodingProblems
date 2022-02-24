#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
	vector<vector<int>> subsets(vector<int> &nums)
	{
		vector<vector<int>> res;
		int len = pow(2, nums.size());
		for (int i = 0; i < len; i++)
		{
			int aux = i;
			vector<int> v = {};
			int bit = 0;
			while (aux > 0)
			{
				if (aux % 2)
				{
					v.push_back(nums[nums.size() - bit - 1]);
				}
				aux /= 2;
				bit++;
			}
			res.push_back(v);
		}
		return res;
	}
};

int main()
{
	vector<int> nums = {1, 2, 3};
	Solution p;
	vector<vector<int>> aux = p.subsets(nums);
	for (vector<int> a : aux)
	{
		for (int i : a)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	cout << aux.size();
}