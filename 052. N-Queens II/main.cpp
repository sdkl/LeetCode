#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void solveOneRow(vector<int>& cur, int row, vector <vector<string>>& result)
	{
		int n = cur.size();
		for (int c = 0; c < n; c++)
		{
			bool fit = true;
			cur[row] = c;
			for (int r = 0; r < row; r++)
			{
				if (cur[r] == c || abs(c - cur[r]) == abs(r - row))
				{
					fit = false;
					break;
				}
			}

			if (fit)
			{
				if (row == n - 1)
				{
					vector<string> s(n, string(n, '.'));
					for (int i = 0; i < n; i++)
					{
						s[i][cur[i]] = 'Q';
					}
					result.push_back(s);
				}
				else
					solveOneRow(cur, row + 1, result);
			}
		}
	}

	int totalNQueens(int n) {
		vector<vector<string>> result;
		if (n > 0)
		{
			vector<int> queens(n, -1);
			solveOneRow(queens, 0, result);
		}
		return result.size();
	}
};

int main()
{
	Solution s;
	cout << s.totalNQueens(6) << endl;
	getchar();
	return 0;
}
