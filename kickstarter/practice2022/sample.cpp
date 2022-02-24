#include <bits/stdc++.h>

using namespace std;

void solve(int i)
{
	int ans;
	int N, M;
	cin >> N >> M;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		sum += x;
	}
	ans = sum % M;
	cout << "Case #" << i << ": " << ans << endl;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
		solve(i + 1);
}