#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int row = matrix.size();
		if (row > 0)
		{
			int col = matrix[0].size(), line = 0;
			while (line < row && matrix[line][col - 1] < target) line++;
			if (line < row)
			{
				int left = 0, right = col - 1, mid;
				while (left <= right)
				{
					mid = (left + right) / 2;
					if (matrix[line][mid] < target)
						left = mid + 1;
					else if (matrix[line][mid] > target)
						right = mid - 1;
					else
						return true;
				}
			}
		}		
		
		return false;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> p = {
		{ 1, 2, 3, 4, 5, 6, 7 },
		{ 8, 9, 10, 11, 12, 13, 14 }
	};
	vector<vector<int>> a = {
		{ 1}
	};

	cout << s.searchMatrix(a,2) << endl;
	getchar();
	return 0;
}