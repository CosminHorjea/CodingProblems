#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool isAnagram(string s1,string s2) {
        // cout<<"Comparing "<<s1<<" and "<<s2<<endl;
        if(s1.length()!=s2.length()) return false;
        vector<int> count(26,0);
        for(int i=0;i<s1.length();i++){
            count[s1[i]-'a']++;
        }
        for(int i=0;i<s2.length();i++){
            count[s2[i]-'a']--;
        }
        for(int i : count){
            if(i!=0) return false;
        }
        return true;

    }
    vector<int> findAnagrams(string s, string p) {
        int k = p.length();
        if(k>s.length()) return {};
        vector<int> res;
        for(int i = 0; i <= s.length()-k ; i++){
            if(isAnagram(s.substr(i,k),p)){
                res.push_back(i);
            }
        }
        return res;
    }
};

int main(){
    Solution* s = new Solution();
    for(int i : s->findAnagrams("aaaaaaaaaa","aaaaaaaaaaaaa")){
        cout<<i<<" ";
    }
}

// "aaaaaaaaaa"
// "aaaaaaaaaaaaa"