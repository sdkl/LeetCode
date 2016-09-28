#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int firstZeroLine = -1, colNum = 0;

		for (int i = 0; i < matrix.size() && firstZeroLine < 0; i++)
		{
			for (int j = 0; j < matrix[i].size() && firstZeroLine < 0; j++)
			{
				if (matrix[i][j] == 0)
					firstZeroLine = i;
			}			
		}
		if (firstZeroLine < 0)
			return;

		for (int i = firstZeroLine; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[i].size(); j++)
			{
				if (matrix[i][j] == 0)
					matrix[firstZeroLine][j] = 0;					
			}
		}

		for (int i = firstZeroLine + 1; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[i].size(); j++)
			{
				if (matrix[i][j] == 0)
				{
					for (int k = 0; k < matrix[i].size(); k++)
						matrix[i][k] = 0;
					break;
				}
			}
		}

		for (int j = 0; j < matrix[firstZeroLine].size(); j++)
		{
			if (matrix[firstZeroLine][j] == 0)
			{
				for (int k = 0; k < matrix.size(); k++)
					matrix[k][j] = 0;
			}
		}
			
		for (int j = 0; j < matrix[firstZeroLine].size(); j++)
		{
			matrix[firstZeroLine][j] = 0;
		}
	}
};

int main()
{
	Solution s;
	vector<vector<int>> p = {
		{ 1, 1, 1, 1, 1, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1 },
	};
	s.setZeroes(p);
	for (auto i : p)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}


	getchar();
	return 0;
}