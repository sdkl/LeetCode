#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		bool col[9][9] = { 0 }, row[9][9] = { 0 }, rect[9][9] = { 0 };
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] == '.')
					continue;				
				int num = board[i][j] - '0' - 1;
				row[i][num] = true;
				col[j][num] = true;
				rect[i / 3 * 3 + j / 3][num] = true;
			}
		}
		solveOne(board, 0, 0, col, row, rect);
	}

	bool solveOne(vector<vector<char>>& board, int curI, int curJ, bool(&col)[9][9], bool(&row)[9][9], bool(&rect)[9][9])
	{
		for (int i = curI; i < 9; i++)
		{
			for (int j = curJ; j < 9; j++)
			{
				if (board[i][j] == '.')
				{
					int rNum = i / 3 * 3 + j / 3;
					for (int k = 0; k < 9; k++)
					{
						if (row[i][k] || col[j][k] || rect[rNum][k])
							continue;
						
						board[i][j] = '0' + k + 1;
						row[i][k] = col[j][k] = rect[rNum][k] = true;
						if (solveOne(board,curI,curJ,col,row,rect))
							return true;
						board[i][j] = '.';
						row[i][k] = col[j][k] = rect[rNum][k] = false;
					}
					return false;
				}
			}
		}

		return true;
	}
};


int main()
{
	Solution s;
	char arr[][9] = {	{ '5', '3', '.', '.', '7', '.', '.', '.', '.' },
						{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
						{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
						{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
						{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
						{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
						{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
						{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
						{ '.', '.', '.', '.', '8', '.', '.', '7', '9' } };

	vector<vector<char>> vec(9, vector<char>(9, '.'));
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			vec[i][j] = arr[i][j];
	}
	s.solveSudoku(vec);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << vec[i][j] << "  ";
		cout << endl;
	}

	getchar();
	return 0;
}