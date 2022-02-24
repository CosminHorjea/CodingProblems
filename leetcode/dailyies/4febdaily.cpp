#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0,res = 0;
        unordered_map<int,int> seen;

        for(int i = 0;i<nums.size();i++) {
            sum += nums[i] == 0 ? -1 : 1;
            if(sum == 0) 
                res = i+1;
            if(seen.find(sum) != seen.end()) 
                res = max(res,i-seen[sum]);
            else 
                seen[sum] = i;
        }
        return res;

    }
};

int main(){
    Solution* s = new Solution();
    cout<<s->findMaxLength({0,1});
}

// "aaaaaaaaaa"
// "aaaaaaaaaaaaa"