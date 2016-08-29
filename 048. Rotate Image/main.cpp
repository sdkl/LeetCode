#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void iSwap(int& a, int& b)
	{
		if (a != b)
		{
			a ^= b;
			b ^= a;
			a ^= b;
		}
	}

	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		for (int i = 0; i < n/2; i++)
		{
			for (int j = i; j < n - 1 - i; j++)
			{
				iSwap(matrix[i][j], matrix[j][n - 1 - i]);
				iSwap(matrix[n - 1 - j][i], matrix[n - 1 - i][n - 1 - j]);
				iSwap(matrix[i][j], matrix[n - 1 - i][n - 1 - j]);
			}
		}
	}
};


int main()
{
	Solution s;
	vector<vector<int>> p({ vector<int>({ 1, 2, 3, 0 }), vector<int>({ 4, 5, 6, 0 }), vector<int>({ 7, 8, 9, 0 }), vector<int>({ 0, 0, 0, 0 }) });
	s.rotate(p);
	for (auto i : p)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}

	getchar();
	return 0;
}