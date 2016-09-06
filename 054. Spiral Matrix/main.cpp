#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> result;

		if (matrix.size() > 0)
		{
			int l = 0, t = 0, b = matrix.size() - 1, r = matrix[0].size() - 1, x = 0, y = 0, xadd = 1, yadd = 0;

			while (r >= l && b >= t)
			{	
				if (x == r && xadd > 0)
				{
					t++;
					xadd = 0;
					yadd = 1;
				}
				else if (y == b && yadd > 0)
				{
					r--;
					xadd = -1;
					yadd = 0;
				}
				else if (x == l && xadd < 0)
				{
					b--;
					xadd = 0;
					yadd = -1;
				}
				else if (y == t && yadd < 0)
				{
					l++;
					xadd = 1;
					yadd = 0;
				}

				result.push_back(matrix[y][x]);
				x += xadd;
				y += yadd;
			}
		}
		
		return result;
	}
};


int main()
{
	Solution s;
	vector<int> result = s.spiralOrder(vector<vector<int>>(
	{ 
		vector<int>({ 1, 2, 3 }),
		vector<int>({ 4, 5, 6 }),
		vector<int>({ 7, 8, 9 })
	}));

	for (auto i : result)
	{
		cout << i << " ";
	}

	getchar();
	return 0;
}