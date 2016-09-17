#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();		
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == 0 && j == 0)
					dp[i][j] = obstacleGrid[i][j] == 0 ? 1 : 0;
				else if (i == 0)
					dp[i][j] = obstacleGrid[i][j] == 0 ? dp[i][j-1] : 0;
				else if (j == 0)
					dp[i][j] = obstacleGrid[i][j] == 0 ? dp[i-1][j] : 0;
				else
					dp[i][j] = obstacleGrid[i][j] == 0 ? dp[i][j-1] + dp[i-1][j]: 0;
			}
		}

		return dp[m - 1][n - 1];
	}
};


int main()
{
	Solution s;
	vector<vector<int>> p({
		{0,0,0},
		{0,1,0},
		{0,0,0}
	});

	cout << s.uniquePathsWithObstacles(p) << endl;
	getchar();
	return 0;
}