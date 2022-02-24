#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> movesBlue = {{1, -1}, {1, 0}, {-1, 0}, {0, -1}, {0, 1}, {-1, 1}};
vector<pair<int, int>> movesRed = {{-1, 0}, {-1, 1}, {0, 1}, {0, -1}, {1, 0}, {1, -1}};

void showMatrix(vector<vector<char>> &grid)
{
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid.size(); j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

bool bfsRed(int row, int col, vector<vector<char>> &grid)
{
	if (row < 0 || row >= grid.size() || col < 0 || col >= grid.size())
	{
		return false;
	}
	if (grid[row][col] != 'R')
	{
		return false;
	}
	stack<pair<int, int>> q;
	map<pair<int, int>, pair<int, int>> parents;
	vector<vector<bool>> visited(grid.size(), vector<bool>(grid.size(), 0));
	q.push({row, col});
	parents[{row, col}] = {-1, -1};
	while (!q.empty())
	{
		pair<int, int> curr = q.top();
		q.pop();
		visited[curr.first][curr.second] = true;
		if (curr.first == grid.size() - 1)
		{
			// found a solution
			while (curr.first != -1)
			{
				grid[curr.first][curr.second] = '.';
				curr = parents[curr];
			}
			return true;
		}
		else
		{
			for (pair<int, int> p : movesRed)
			{
				int nrow = curr.first + p.first;
				int ncol = curr.second + p.second;
				if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid.size())
				{
					if (grid[nrow][ncol] == 'R' && !visited[nrow][ncol])
					{
						q.push({nrow, ncol});
						parents[{nrow, ncol}] = {curr.first, curr.second};
					}
				}
			}
		}
	}
	return false;
}

bool bfsBlue(int row, int col, vector<vector<char>> &grid)
{
	/**
	 * @todo Dfs that goes up and right
	 * currently implemented bfs doesnt recognize impossible casese like
	 * ......
		.BBBR.
		BBBBBB
		B..BBB
		RRRRRR
		RRRRRR

		because the middle line gets broken and then the seong path doesnt work
		we could use a dfs that goes up and right , and that might sole this

		! do it iterative. below here in a stack, you need the path
	 */
	if (row < 0 || row >= grid.size() || col < 0 || col >= grid.size())
	{
		return false;
	}
	if (grid[row][col] != 'B')
	{
		return false;
	}
	stack<pair<int, int>> q;
	map<pair<int, int>, pair<int, int>> parents;
	vector<vector<bool>> visited(grid.size(), vector<bool>(grid.size(), 0));
	q.push({row, col});
	parents[{row, col}] = {-1, -1};
	while (!q.empty())
	{
		pair<int, int> curr = q.top();
		q.pop();
		visited[curr.first][curr.second] = true;
		if (curr.second == grid.size() - 1)
		{
			// found a solution
			// cout << "Solutie: ";
			while (curr.first != -1)
			{
				grid[curr.first][curr.second] = '.';
				curr = parents[curr];
				// cout << "(" << curr.first << " " << curr.second << ")";
			}
			// cout << endl;
			return true;
		}
		else
		{
			for (pair<int, int> p : movesBlue)
			{
				int nrow = curr.first + p.first;
				int ncol = curr.second + p.second;
				if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid.size())
				{
					if (grid[nrow][ncol] == 'B' && !visited[nrow][ncol])
					{
						q.push({nrow, ncol});
						parents[{nrow, ncol}] = {curr.first, curr.second};
					}
				}
			}
		}
	}
	return false;
}

void solve(int i)
{
	int N;
	string ans = "";
	cin >> N;
	int B = 0, R = 0;
	vector<vector<char>> grid(N, vector<char>(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> grid[i][j];
			if (grid[i][j] == 'B')
			{
				B++;
			}
			else if (grid[i][j] == 'R')
			{
				R++;
			}
		}
	}
	if (abs(R - B) > 1)
	{
		ans = "Impossible"; // due to too many moves of one player
	}
	for (int i = 0; i < N; i++)
	{
		if (bfsRed(0, i, grid))
		{
			if (ans.size() > 0)
			{
				ans = "Impossible";
			}
			else
			{
				ans = "Red wins";
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (bfsBlue(i, 0, grid))
		{
			if (ans.size() > 0)
			{
				ans = "Impossible";
			}
			else
			{
				ans = "Blue wins";
			}
		}
	}

	// showMatrix(grid);
	if (ans.size() == 0)
	{
		ans = "Nobody wins";
	}
	if (ans[0] == 'R')
	{
		if (B > R)
		{
			ans = "Impossible";
		}
	}
	if (ans[0] == 'B')
	{
		if (R > B)
		{
			ans = "Impossible";
		}
	}
	cout << "Case #" << i << ": " << ans << endl;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
		solve(i + 1);
}
