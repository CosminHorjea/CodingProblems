#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
	vector<vector<int>> permute(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		do
		{
			res.push_back(nums);
		} while (next_permutation(nums.begin(), nums.end()));
	}
	vector<string> letterCasePermutation(string s)
	{
		vector<string> res;
		vector<int> pos;
		int k = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (isalpha(s[i]))
			{
				pos.push_back(i);
				s[i] = tolower(s[i]);
			}
		}
		k = pos.size();
		if (!k)
			return {s};
		for (int i = 0; i < pow(2, k); i++)
		{
			string ans = s;
			int aux = i;
			int idx = 0;
			do
			{
				if (aux % 2 == 1)
				{
					ans[pos[k - idx - 1]] = toupper(ans[pos[k - idx - 1]]);
				}
				else
				{
					ans[pos[k - idx - 1]] = tolower(ans[pos[k - idx - 1]]);
				}
				idx++;
				aux /= 2;
			} while (aux > 0);
			cout << ans << " ";
			res.push_back(ans);
		}
		return res;
	}
};

int main()
{
	Solution p;
	// p.letterCasePermutation("Jw");
	// p.letterCasePermutation("c");
	// p.letterCasePermutation("3z4");
	p.letterCasePermutation("A1b2");
}