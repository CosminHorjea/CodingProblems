#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
	int shortestPathLength(vector<vector<int>> &graph)
	{
		int N = graph.size();
		// we have a bitmast to see what nodes we have visited
		// 101 - means that we visited nodes 0 and 2, and so on,
		// we want to keep track of a visited node and the state that is visited in at the same time
		vector<vector<bool>> visited(N, vector<bool>(1 << N, false));

		queue<pair<int, int>> q;
		// each node starts with the state 000i000 where i is one ant the i-th position
		// meaning that we visited that node in this state
		for (int i = 0; i < N; ++i)
		{
			q.push({i, 1 << i});
			visited[i][1 << i] = true;
		}

		int ans = 0;
		while (!q.empty())
		{
			int size = q.size();
			// we go through the full queue, and push things at the same time, but we are only interested in the current state
			// because it will give us the minimum distance
			for (int i = 0; i < size; i++)
			{
				pair<int, int> p = q.front();
				q.pop();
				for (auto next : graph[p.first])
				{
					int next_state = p.second | (1 << next);
					if (next_state == (1 << N) - 1)
						return ans + 1;

					if (!visited[next][next_state])
					{
						q.push({next, next_state});
						visited[next][next_state] = true;
					}
				}
			}
			ans++;
		}
		return 0;
	}
};

int main()
{
	vector<vector<int>> g = {{1}, {0, 2, 4}, {1, 3, 4}, {2}, {1, 2}};
	Solution p;
	cout << p.shortestPathLength(g);
}