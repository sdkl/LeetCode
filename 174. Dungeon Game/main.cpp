#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		if (dungeon.empty() || dungeon[0].empty())
			return 1;

		int m = dungeon.size(), n = dungeon[0].size();
		vector<vector<int>> minHP(m + 1, vector<int>(n+1,INT_MAX));
		minHP[m][n - 1] = minHP[m - 1][n] = 1;
		for (int i = m - 1; i >= 0; i--)
		{
			for (int j = n - 1; j >= 0; j--)
			{
				int m = min(minHP[i][j + 1], minHP[i + 1][j]) - dungeon[i][j];
				minHP[i][j] = m <= 0 ? 1 : m;
			}
		}

		return minHP[0][0];
	}
};

int main()
{
	Solution s;
	vector<vector<int>> v = {
		{-2, -3, 3},
		{-5, -10, 1},
		{10, 30, -5},
	};

	cout << s.calculateMinimumHP(v) << endl;


	getchar();
	return 0;
}