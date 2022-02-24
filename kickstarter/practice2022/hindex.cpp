#include <bits/stdc++.h>

using namespace std;

void solve(int i)
{
	int N, curr, max_so_far = 1, pos;
	cin >> N;
	priority_queue<int> q;
	cout << "Case #" << i << ": ";
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> curr;
		if (curr > ans)
		{
			q.push(-curr);
		}
		while (q.size() && -q.top() <= ans)
		{
			q.pop();
		}
		if (q.size() > ans)
		{
			ans++;
		}
		cout << ans << " ";
	}
	cout << endl;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
		solve(i + 1);
}
/*
1 3 3 2 2 15
1 - 1
2 - 2
3 - 2
15
*/