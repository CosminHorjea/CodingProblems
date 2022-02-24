#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
	bool matches(string s1, string s2)
	{
		int aux = 0;
		for (int i = 0; i < s1.length(); i++)
		{
			if (s1[i] != s2[i])
			{
				aux++;
				if (aux > 1)
					return false;
			}
		}
		return true;
	}

	int ladderLength(string beginWord, string endWord, vector<string> &wordList)
	{
		queue<pair<string, int>> curr;
		unordered_set<string> not_seen(wordList.begin(), wordList.end());
		unordered_set<string> seen;
		curr.push({beginWord, 1});
		seen.insert(beginWord);
		not_seen.erase(beginWord);
		while (!curr.empty())
		{
			pair<string, int> c = curr.front();
			cout << c.first << " " << c.second << endl;
			curr.pop();
			vector<string> found;
			for (string s : not_seen)
			{
				if (seen.find(s) == seen.end() && matches(s, c.first))
				{
					seen.insert(s);
					found.push_back(s);
					curr.push({s, c.second + 1});
					if (s == endWord)
					{
						return c.second + 1;
					}
				}
			}
			for (string s : found)
			{
				not_seen.erase(s);
			}
		}
		return 0;
	}
};

int main()
{
	vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
	Solution p;
	cout << p.ladderLength("hit", "cog", wordList);
}