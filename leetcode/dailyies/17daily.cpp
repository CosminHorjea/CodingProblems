#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
	int N, K, target;
	vector<int> x;
	vector<vector<int>> output;
	vector<int> candidates;

	vector<vector<int>> combinationSum(vector<int> &_candidates, int _target)
	{
		candidates = _candidates;
		target = _target;
		N = candidates.size();
		x.reserve(target);
		back(0);
		return output;
	}
	bool OK(int k)
	{
		for (int i = 0; i < k; i++)
		{
			if (x[i] > x[k])
				return false;
		}
		int sum = 0;
		for (int i = 0; i <= k; i++)
		{
			sum += x[i];
		}
		if (sum > target)
		{
			return false;
		}
		return true;
	}
	bool sol(int k)
	{
		int sum = 0;
		for (int i = 0; i <= k; i++)
		{
			sum += x[i];
		}
		return target == sum;
	}
	void back(int k)
	{
		for (int i = 0; i < N; ++i)
		{
			x[k] = candidates[i];
			if (OK(k))
			{
				if (sol(k))
				{
					vector<int> aux;
					for (int i = 0; i <= k; i++)
					{
						aux.push_back(x[i]);
					}
					output.push_back(aux);
				}
				else
				{
					back(k + 1);
				}
			}
		}
	}
};

int main()
{
	Solution p;
	vector<int> v = {2, 3, 6, 7};
	vector<vector<int>> sol = p.combinationSum(v, 7);
	for (int i : sol[0])
	{
		cout << i;
	}
}