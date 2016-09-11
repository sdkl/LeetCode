#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> result(n, vector<int>(n));
		int i = 1,l = 0, t = 0, b = n - 1, r = n - 1, x = 0, y = 0, xadd = 1, yadd = 0;
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

			result[y][x] = i++;
			x += xadd;
			y += yadd;
		}

		return result;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> result = s.generateMatrix(6);
	for (auto i : result)
	{
		cout << "[";
		for (auto j : i)
			cout << setw(5) << j << " ";
		cout << "]" << endl;
	}

	getchar();
	return 0;
}