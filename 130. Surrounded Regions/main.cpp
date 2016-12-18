#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if (board.empty()) return;
		vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
		unordered_set<int> isO;
		queue<pair<int, int>> bfs;

		for (int j = 0; j < board[0].size(); j++)
		{
			bfs.push(pair<int,int>(0, j));
			bfs.push(pair<int, int>(board.size() - 1, j));
		}

		for (int i = 0; i < board.size(); i++)
		{
			bfs.push(pair<int, int>(i, 0));
			bfs.push(pair<int, int>(i, board[0].size() - 1));
		}

		while (!bfs.empty())
		{
			pair<int, int> w = bfs.front();
			bfs.pop();

			int i = w.first, j = w.second;
			if (visited[i][j] == true)
				continue;

			visited[i][j] = true;
			if (board[i][j] == 'O')
				isO.insert(i*board[i].size() + j);
			else
				continue;

			if (i - 1 >= 0)
				bfs.push(pair<int, int>(i - 1, j));
			if (i + 1<board.size())
				bfs.push(pair<int, int>(i + 1, j));
			if (j - 1 >= 0)
				bfs.push(pair<int, int>(i, j - 1));
			if (j + 1 < board[0].size())
				bfs.push(pair<int, int>(i, j + 1));

		}
		
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				if (board[i][j] == 'O' && isO.count(i*board[i].size() + j) == 0)
					board[i][j] = 'X';
			}
		}		
	}
};

int main()
{
	Solution s;
	vector<vector<char>> board = {
		{ 'X', 'X', 'X', 'X' },
		{ 'X', 'O', 'O', 'X' },
		{ 'X', 'X', 'O', 'X' },
		{ 'X', 'O', 'X', 'X' }
	};
	s.solve(board);
	for (auto i : board)
	{
		for (auto j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}


	getchar();
	return 0;
}