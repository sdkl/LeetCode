#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == 0 && j == 0)
					;
				else if (i == 0)
					grid[i][j] += grid[i][j - 1];
				else if (j == 0)
					grid[i][j] += grid[i - 1][j];
				else
					grid[i][j] += grid[i][j - 1] > grid[i - 1][j] ? grid[i - 1][j] : grid[i][j - 1];
			}
		}

		return grid[m - 1][n - 1];
	}
};


int main()
{
	Solution s;
	vector<vector<int>> p({
		{ 0, 3, 0 },
		{ 0, 1, 3 },
		{ 0, 2, 0 }
	});

	cout << s.minPathSum(p) << endl;
	getchar();
	return 0;
}