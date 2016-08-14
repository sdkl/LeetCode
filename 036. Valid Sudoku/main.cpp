#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		if (board.size() == 0 || board.size() % 3 != 0 || board.size() < 3)
			return false;

		vector<unordered_set<char>> colMap(board.size(), unordered_set<char>()), sqrtMap(board.size() / 3 * board.size() / 3, unordered_set<char>());
		unordered_set<char> rowMap;

		for (int i = 0; i < board.size(); i++)
		{
			if (board.size() != board[i].size())
				return false;

			rowMap.clear();
			for (int j = 0; j < board[i].size(); j++)
			{
				if (board[i][j] == '.')
					continue;
				if (board[i][j] - '0'< 0 || board[i][j] - '0'> 9)
					return false;
				if (rowMap.count(board[i][j]) != 0 || colMap[j].count(board[i][j]) != 0 || sqrtMap[i / 3 * 3 + j / 3].count(board[i][j]) != 0)
					return false;
				else
				{
					rowMap.insert(board[i][j]);
					colMap[j].insert(board[i][j]);
					sqrtMap[i / 3 * 3 + j / 3].insert(board[i][j]);
				}					
			}
		}

		return true;
	}
};

int main()
{
	Solution s;
	char arr[][9] = {	{ '5', '3', '.', '.', '.', '.', '.', '.', '.' }, 
						{ '6', '5', '.', '.', '.', '.', '.', '.', '.' }, 
						{ '.', '.', '.', '.', '.', '.', '.', '.', '.' }, 
						{ '.', '.', '.', '.', '.', '.', '.', '.', '.' }, 
						{ '.', '.', '.', '.', '.', '.', '.', '.', '.' }, 
						{ '.', '.', '.', '.', '.', '.', '.', '.', '.' }, 
						{ '.', '.', '.', '.', '.', '.', '.', '.', '.' }, 
						{ '.', '.', '.', '.', '.', '.', '.', '.', '.' }, 
						{ '.', '.', '.', '.', '.', '.', '.', '.', '.' }	};

	vector<vector<char>> vec(9,vector<char>(9,'.'));
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			vec[i][j] = arr[i][j];
	}
	cout << s.isValidSudoku(vec) << endl;

	getchar();
	return 0;
}