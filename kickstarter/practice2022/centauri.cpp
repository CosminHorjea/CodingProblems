#include <bits/stdc++.h>

using namespace std;

string vowels = "AEIOUaeiou";

void solve(int i)
{
	string ans;
	string kingdom;
	cin >> kingdom;
	char last = kingdom[kingdom.length() - 1];
	if (strchr(vowels.c_str(), last) != NULL)
	{
		ans = "Alice";
	}
	else if (last != 'y' && last != 'Y')
	{
		ans = "Bob";
	}
	else
	{
		ans = "nobody";
	}
	cout << "Case #" << i << ": " << kingdom << " is ruled by " << ans << "." << endl;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
		solve(i + 1);
}