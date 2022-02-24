#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
	int N, K;
	vector<int> x;
	vector<vector<int>> output;

	vector<vector<int>> combine(int n, int k)
	{
		N = n;
		K = k;
		for (int i = 0; i < k; i++)
		{
			x.push_back(0);
		}
		back(0);

		return output;
	}
	bool OK(int k)
	{
		for (int i = 0; i < k; i++)
		{
			if (x[i] <= x[k])
				return false;
		}
		return true;
	}
	void back(int k)
	{
		for (int i = 1; i <= N; ++i)
		{
			x[k] = i;
			cout << endl;
			if (OK(k))
			{
				if (k == K - 1)
				{
					output.push_back(x);
				}
				else
					back(k + 1);
			}
		}
	}
};

int main()
{
	Solution p;
	vector<vector<int>> sol = p.combine(4, 2);
}