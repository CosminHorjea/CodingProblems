#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
    // sort a linked list with bubble sort
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        int swapped = 1;
        ListNode *curr = head;
        vector<int> v;
        while (curr)
        {
            v.push_back(curr->val);
            curr = curr->next;
        }
        sort(v.begin(), v.end());
        curr = head;
        for (int i = 0; i < v.size(); i++)
        {
            curr->val = v[i];
            curr = curr->next;
        }
        return head;
    }
};

int main()
{
}