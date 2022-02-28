#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;
        int last = nums[0];
        int i = 1;
        for (i = 1; i < nums.size(); i++)
        {
            if (nums[i] == (nums[i - 1] + 1))
            {
                continue;
            }
            else
            {
                stringstream ss;
                if (nums[i - 1] == last)
                {
                    ss << last;
                }
                else
                {
                    ss << last << "->" << nums[i - 1];
                }
                ans.push_back(ss.str());
                last = nums[i];
            }
        }
        stringstream ss;
        if (nums[i - 1] == last)
        {
            ss << last;
        }
        else
        {
            ss << last << "->" << nums[i - 1];
        }
        ans.push_back(ss.str());
        last = nums[i];
        return ans;
    }
};

int main()
{
    vector<int> nums = {0, 2, 3, 4, 6, 8, 9};
    Solution p;
    for (string s : p.summaryRanges(nums))
    {
        cout << s << endl;
    }
}