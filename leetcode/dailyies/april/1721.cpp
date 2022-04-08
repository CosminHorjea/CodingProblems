#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (head == NULL) return NULL;

        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* first = dummy;
        while (k-- > 0) {
            first = first->next;
        }

        ListNode *second = dummy, *temp = first;
        while (temp != NULL) {
            second = second->next;
            temp = temp->next;
        }

        int val = first->val;
        first->val = second->val;
        second->val = val;

        return dummy->next;
    }
};