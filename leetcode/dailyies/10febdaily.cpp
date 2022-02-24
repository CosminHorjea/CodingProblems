#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow=head, *fast = head;
        while(fast->next){
            fast=fast->next;
            if(fast->next){
                fast=fast->next;
            }
            slow=slow->next;
        }
        return slow;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // creata a new node when on n-th node then go at the same time
        ListNode* aux = head;
        for(int i=0;i<n;i++){
            aux=aux->next;
        }
        ListNode* aux2 = head;
        while(aux){
            aux=aux->next;
            aux2=aux2->next;
        }
        if(aux2->next->next){
            aux2->next=aux2->next->next;
        }else{
            head = aux2->next;
        }
        return head;
    }

    int lengthOfLongestSubstring(string s) {
        int n = s.length(),ans = 0;
        vector<int> index(128);
        for(int j=0,i=0;j<n;j++){
            i = max(index[s[j]],i);
            ans = max(ans,j-i+1);
            index[s[j]] = j+1;
        }
        return ans;
    }
};
int main(){
    Solution p;
    // ListNode *head = new ListNode(1);
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);
    // head->next->next->next->next->next = new ListNode(6);

    // ListNode *res = p.middleNode(head);
    // cout<<res->val;
    cout<<p.lengthOfLongestSubstring("au")<<endl;
    cout<<p.lengthOfLongestSubstring(" ")<<endl;
    cout<<p.lengthOfLongestSubstring("pwwkew")<<endl;
    cout<<p.lengthOfLongestSubstring("dvdf")<<endl;
}