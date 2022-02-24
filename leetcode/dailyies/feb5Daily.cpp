#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr){};
	ListNode(int x, ListNode *next) : val(x), next(next){};
};

class Solution
{
public:
	ListNode *mergeKLists(vector<ListNode *> &lists)
	{
		if (lists.size() == 0)
		{
			return NULL;
		}
		priority_queue<pair<int, ListNode *>> nodes;
		ListNode *res = new ListNode();
		ListNode *aux = res;
		ListNode *prev = aux;
		for (ListNode *aux : lists)
		{
			if (aux != NULL)
			{
				nodes.push({-aux->val, aux});
			}
		}
		while (nodes.size() > 0)
		{
			pair<int, ListNode *> top = nodes.top();
			nodes.pop();
			aux->val = -top.first;
			aux->next = new ListNode();
			prev = aux;
			aux = aux->next;
			if (top.second->next)
			{
				nodes.push({-top.second->next->val, top.second->next});
			}
		}
		prev->next = NULL;
		if (res->val == 0 && res->next == NULL)
		{
			delete res;
			return NULL;
		}
		return res;
	}
};

int main()
{
	ListNode *l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
	ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
	ListNode *l3 = new ListNode(2, new ListNode(6));
	vector<ListNode *> lists;
	// lists.push_back(NULL);
	lists.push_back(l1);
	lists.push_back(l2);
	lists.push_back(l3);
	Solution *p = new Solution();
	ListNode *res = p->mergeKLists(lists);
	while (res)
	{
		cout << res->val << " ";
		res = res->next;
	}
}