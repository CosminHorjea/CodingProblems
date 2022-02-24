#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
	bool isValid(string s)
	{
		// is s a valid paracheses sequence
		stack<char> st;

		for (char c : s)
		{
			if (c == '(' || c == '[' || c == '{')
				st.push(c);
			else
			{
				char top = st.top();
				if (c == ')' && top == '(')
				{
					st.pop();
				}
				else if (c == ']' && top == ']')
				{
					st.pop();
				}
				else if (c == '}' && top == '}')
				{
					st.pop();
				}
				else
					return false;
			}
		}
		return true;
	}
	// traverse a binary tree in preorder
	vector<int> preorderTraversal(TreeNode *root)
	{
		vector<int> ans;

		if (root == nullptr)
			return ans;

		stack<TreeNode *> st;

		TreeNode *curr = root;

		while (!st.empty() || curr != NULL)
		{
			cout << "Curr: " << curr->val << endl;
			while (curr != NULL)
			{
				ans.push_back(curr->val);

				if (curr->right != NULL)
					st.push(curr->right);
				curr = curr->left;
			}

			if (!st.empty())
			{
				curr = st.top();
				st.pop();
			}
		}
		return ans;
	}

	vector<int> inorderTraversal(TreeNode *root)
	{
		vector<int> ans;

		if (root == nullptr)
			return ans;

		stack<TreeNode *> st;
		TreeNode *curr = root;

		while (!st.empty() || curr != NULL)
		{
			while (curr != NULL)
			{
				st.push(curr);
				curr = curr->left;
			}

			curr = st.top();
			st.pop();
			ans.push_back(curr->val);
			curr = curr->right;
		}
	}

	vector<int> postorderTraversal(TreeNode *root)
	{
		vector<int> ans;

		if (root == nullptr)
			return ans;

		stack<TreeNode *> st1, st2;
		TreeNode *curr = root;
		st1.push(root);
		// traverse in postorder
		while (!st1.empty())
		{
			curr = st1.top();
			st1.pop();
			st2.push(curr);
			if (curr->left != NULL)
				st1.push(curr->left);
			if (curr->right != NULL)
				st1.push(curr->right);
		}

		while (!st2.empty())
		{
			ans.push_back(st2.top()->val);
			st2.pop();
		}

		return ans;
	}

	/**
	 * @brief Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
	 *
	 * @param root
	 * @return vector<vector<int>>
	 */
	vector<vector<int>> levelOrder(TreeNode *root)
	{
		vector<vector<int>> ans;
		if (root == nullptr)
			return ans;

		queue<TreeNode *> q;
		q.push(root);
		while (!q.empty())
		{
			vector<int> level;
			int size = q.size();
			for (int i = 0; i < size; i++)
			{
				TreeNode *curr = q.front();
				q.pop();
				level.push_back(curr->val);
				if (curr->left != NULL)
					q.push(curr->left);
				if (curr->right != NULL)
					q.push(curr->right);
			}
			ans.push_back(level);
		}
		return ans;
	}

	/**
	 * @brief
	 * A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node
	 */
	int maxDepth(TreeNode *root)
	{
		if (root == nullptr)
			return 0;
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		return max(left, right) + 1;
	}
	// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
	bool isSymmetric(TreeNode *root)
	{
		if (root == nullptr)
			return true;
		return isSymmetric(root->left, root->right);
	}
	bool isSymmetric(TreeNode *left, TreeNode *right)
	{
		if (left == nullptr && right == nullptr)
			return true;
		else if (left == nullptr || right == nullptr)
			return false;
		if (left->val != right->val)
			return false;
		return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
	}

	// Given the root of a binary tree, invert the tree, and return its root.

	TreeNode *invertTree(TreeNode *root)
	{
		if (root == nullptr)
			return nullptr;
		TreeNode *left = invertTree(root->left);
		TreeNode *right = invertTree(root->right);
		root->left = right;
		root->right = left;
		return root;
	}

	// Given a binary tree, return the inorder traversal of its nodes' values.
	vector<int> inorderTraversal(TreeNode *root)
	{
		vector<int> ans;
		if (root == nullptr)
			return ans;

		stack<TreeNode *> st;
		TreeNode *curr = root;

		while (!st.empty() || curr != NULL)
		{
			while (curr != NULL)
			{
				st.push(curr);
				curr = curr->left;
			}
			curr = st.top();
			st.pop();
			ans.push_back(curr->val);
			curr = curr->right;
		}
		return ans;
	}

	// Given a binary tree, return the preorder traversal of its nodes' values.
	vector<int> preorderTraversal(TreeNode *root)
	{
		vector<int> ans;

		if (root == nullptr)
			return ans;

		stack<TreeNode *> st;
		TreeNode *curr = root;

		while (!st.empty() || curr != NULL)
		{
			while (curr != NULL)
			{
				if (!root)
					return ans;
				ans.push_back(curr->val);
				st.push(curr);
				curr = curr->left;
			}
			curr = st.top();
			st.pop();
			curr = curr->right;
		};
		return ans;
	}

	// Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

	bool hasPathSum(TreeNode *root, int targetSum)
	{
		if (root == nullptr)
			return false;
		if (root->left == nullptr && root->right == nullptr)
			return root->val == targetSum;
		return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
	}

	// search in a bst
	TreeNode *searchBST(TreeNode *root, int val)
	{
		if (root == nullptr)
			return nullptr;
		if (root->val == val)
			return root;
		if (root->val > val)
			return searchBST(root->left, val);
		else
			return searchBST(root->right, val);
	}

	// insert in a bst
	TreeNode *insertIntoBST(TreeNode *root, int val)
	{
		if (root == nullptr)
			return new TreeNode(val);
		if (root->val > val)
			root->left = insertIntoBST(root->left, val);
		else
			root->right = insertIntoBST(root->right, val);
		return root;
	}

	// validate bst
	bool isValidBST(TreeNode *root)
	{
		if (root == nullptr)
			return true;
		return isValidBST(root->left, INT_MIN, root->val) && isValidBST(root->right, root->val, INT_MAX);
	}

	bool isValidBST(TreeNode *root, int min, int max)
	{
		if (root == nullptr)
			return true;
		if (root->val <= min || root->val >= max)
			return false;
		return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
	}

	// Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.
	bool findTarget(TreeNode *root, int k)
	{
		if (root == nullptr)
			return false;
		unordered_set<int> s;
		return findTarget(root, k, s);
	}

	bool findTarget(TreeNode *root, int k, unordered_set<int> &s)
	{
		if (root == nullptr)
			return false;
		if (s.find(k - root->val) != s.end())
			return true;
		s.insert(root->val);
		return findTarget(root->left, k, s) || findTarget(root->right, k, s);
	}

	// Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
	{
		if (root == nullptr)
			return nullptr;
		if (root->val > p->val && root->val > q->val)
			return lowestCommonAncestor(root->left, p, q);
		if (root->val < p->val && root->val < q->val)
			return lowestCommonAncestor(root->right, p, q);
		return root;
	}
};

// A queue with stacks
class MyQueue
{

	stack<int> st1;
	stack<int> st2;

public:
	MyQueue()
	{
		st1 = stack<int>();
		st2 = stack<int>();
	}

	void push(int x)
	{
		st1.push(x);
	}

	int pop()
	{
		while (st1.size())
		{
			st2.push(st1.top());
			st1.pop();
		}
		int res = st2.top();
		st2.pop();
		while (st2.size())
		{
			st1.push(st2.top());
			st2.pop();
		}
		return res;
	}

	int peek()
	{
		while (st1.size())
		{
			st2.push(st1.top());
			st1.pop();
		}
		int res = st2.top();
		return res;
	}

	bool empty()
	{
		return st1.empty() && st2.empty();
	}
};
int main()
{
	TreeNode *root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);
	Solution s;
	vector<int> ans = s.preorderTraversal(root);
	for (int i : ans)
		cout << i << " ";
}