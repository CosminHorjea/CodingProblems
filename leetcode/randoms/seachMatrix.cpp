#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int i = 0, j = 0;
        int N = matrix.size();
        int M = matrix[0].size();
        cout << N << " " << M;
        for (i = 0; i < N; i++)
        {
            if (matrix[i][0] >= target)
                break;
        }
        cout << N << " " << M;
        if (matrix[i][0] == target)
            return true;

        // while ((j < M) && (matrix[i][j] < target))
        //     j++;
        // if (j > 0)
        //     j = j - 1;
        if ((i < N) && (j < M))
            return matrix[i][j] == target;
        return false;
    }
};

int main()
{
    Solution p;
    vector<vector<int>> m = {{1}};
    cout << p.searchMatrix(m, 1) << endl;
}