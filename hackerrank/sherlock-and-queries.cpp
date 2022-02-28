// https://github.com/M4573R/competitive-programming-archive/blob/6d2ee75ef645ad4f0959cb587995a17dc901d1a2/hackerrank/mathematics/summations-and-algebra/sherlock_and_queries.cpp
// this link passes all the test cases
// but i can't, for the love of god, figure out why
// mine doesn't produce right answers beside sample case
#include <bits/stdc++.h>

using namespace std;

int M = 1000000007;

int mod(int a, int m = M)
{
	return (a % m + m) % m;
}

vector<int> solve(vector<int> A, vector<int> B, vector<int> C)
{
	int N = A.size();
	int M = B.size();

	for (int i = 1; i <= M; i++)
	{
		int aux = B[i - 1];

		while (aux < N)
		{
			A[aux - 1] = mod(mod(A[aux - 1]) * mod(C[i - 1]));
			aux += B[i - 1];
		}
	}

	// for (int i = 1; i <= M; i++)
	// {
	// 	for (int j = 1; j <= N; j++)
	// 	{
	// 		if (j % B[i - 1] == 0)
	// 		{
	// 			A[j - 1] = mod(A[j - 1] * C[i - 1]);
	// 		}
	// 	}
	// }

	for (int i : A)
	{
		cout << i << " ";
	}
	cout << endl;

	return A;
}

int main()
{
	solve({1, 2, 3, 4}, {4, 4, 4}, {13, 29, 71});
	// cout << solve({1, 2, 3, 4}, {1, 2, 3}, {13, 29, 71}) << endl;
}