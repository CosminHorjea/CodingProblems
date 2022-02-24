#include <bits/stdc++.h>

using namespace std;

int getScore(vector<bool> current, vector<vector<bool>> &friends)
{
	int res = 0;
	int l = current.size();
	for (vector<bool> v : friends)
	{
		for (int i = 0; i < l; i++)
		{
			if (current[i] != v[i])
			{
				res++;
			}
		}
	}
	return res;
}

void solve(int i)
{
	int N, M, P;
	// string ans = "";
	int ans = INT_MAX;
	string line;
	cin >> N >> M >> P;
	// cout << "Citesc: " << N << M << P;
	vector<vector<bool>> friends(N, vector<bool>(P, 0));
	vector<int> ones(P, 0);
	vector<vector<bool>> forbidden(M, vector<bool>(P, 0));
	set<vector<bool>> fbd;
	priority_queue<pair<int, int>> q;
	vector<int> solution(P, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> line;
		for (int j = 0; j < P; j++)
		{
			if (line[j] == '1')
			{
				friends[i][j] = 1;
				ones[j]++;
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> line;
		for (int j = 0; j < P; j++)
		{
			if (line[j] == '1')
			{
				forbidden[i][j] = 1;
			}
		}
		fbd.insert(forbidden[i]);
	}

	vector<vector<bool>> T = {{}};
	for (int k = 0; k < P; k++)
	{
		vector<pair<int, vector<bool>>> candidates;
		for (vector<bool> v : T)
		{
			v.push_back(1);
			int score = getScore(v, friends);
			candidates.push_back({score, v});
			v[v.size() - 1] = 0;
			score = getScore(v, friends);
			candidates.push_back({score, v});
		}
		sort(candidates.begin(), candidates.end());
		T.clear();
		for (int i = 0; i < min(101, (int)candidates.size()); i++)
		{
			T.push_back(candidates[i].second);
		}
	}
	for (vector<bool> v : T)
	{
		if (fbd.find(v) == fbd.end())
		{
			ans = min(ans, getScore(v, friends));
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
