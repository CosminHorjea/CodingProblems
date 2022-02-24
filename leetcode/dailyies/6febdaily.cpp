#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <queue>

using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        map<int,int> freq;
        queue<int> unused_indices;
        for(int i = 0;i<nums.size();i++) {
            freq[nums[i]]++;
            if(freq[nums[i]] > 2)
            {
                unused_indices.push(i);
            }else{
                k++;
                if(unused_indices.size() > 0)
                {
                    nums[unused_indices.front()] = nums[i];
                    unused_indices.pop();
                    unused_indices.push(i);
                }
            }      
        }
        return k;
    }
};

int main(){
    Solution* s = new Solution();
    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    int k = s->removeDuplicates(nums);
    for(int i = 0;i<k;i++)
        cout<<nums[i]<<" ";
    cout<<endl;
    cout<<k;
}

// "aaaaaaaaaa"
// "aaaaaaaaaaaaa"