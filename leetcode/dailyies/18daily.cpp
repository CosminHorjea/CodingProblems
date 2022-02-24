#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        if(k >= num.length()){
            return "0";
        }
        if(num.size()==0){
            return "0";
        }
        stack<int> st;
        //10200
        for(char c : num){
            int n =  c - '0';
            // cout<<n;
            // cout<<st.size();
            // cout<<endl;
            if(st.size()){
                while((st.top() > n) && (k > 0)){
                    st.pop();
                    k--;
                    if(st.empty())
                        break;
                }
            }
            // cout<<"Pushed: "<<n<<endl;
            st.push(n);
        }
        // 0200
        while(!st.empty()){
            ans+='0'+st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i =0;
        while(ans[i++]=='0'){}

        return ans.substr(i-1);
    }
};
int main(){
    Solution p;
    cout<<p.removeKdigits("1432219",3)<<endl;
    cout<<p.removeKdigits("10200",1)<<endl;
    cout<<p.removeKdigits("10",2)<<endl;

    return 0;
}