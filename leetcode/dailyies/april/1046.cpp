#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> sto(stones.begin(), stones.end());
        while (sto.size() > 1) {
            int first = sto.top();
            sto.pop();
            int second = sto.top();
            sto.pop();
            int res = first - second;
            if (res > 0) {
                sto.push(res);
            }
        }
        if (sto.size()) {
            return sto.top();
        }
        return 0;
    }
};
