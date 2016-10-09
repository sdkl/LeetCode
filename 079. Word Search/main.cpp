#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
	bool checkExist(vector<vector<char>>& board, string& word, int cur, int i, unordered_set<int>& s)
	{
		if (cur >= word.length())
			return true;

		int x = i / board[0].size(), y = i%board[0].size();
		if (board[x].size() > y + 1 && board[x][y + 1] == word[cur])
		{
			int n = x*board[0].size() + y + 1;
			if (s.find(n) == s.end())
			{
				s.insert(n);
				if (checkExist(board, word, cur + 1, n, s))
					return true;
				s.erase(n);
			}			
		}			
		if (0 <= y - 1 && board[x][y - 1] == word[cur])
		{
			int n = x*board[0].size() + y - 1;
			if (s.find(n) == s.end())
			{
				s.insert(n);
				if (checkExist(board, word, cur + 1, n, s))
					return true;
				s.erase(n);
			}
		}
		if (board.size() > x + 1 && board[x + 1][y] == word[cur])
		{
			int n = (x + 1)*board[0].size() + y;
			if (s.find(n) == s.end())
			{
				s.insert(n);
				if (checkExist(board, word, cur + 1, n, s))
					return true;
				s.erase(n);
			}
		}
		if (0 <= x - 1 && board[x - 1][y] == word[cur])
		{
			int n = (x-1)*board[0].size() + y;
			if (s.find(n) == s.end())
			{
				s.insert(n);
				if (checkExist(board, word, cur + 1, n, s))
					return true;
				s.erase(n);
			}
		}

		return false;
	}

	bool exist(vector<vector<char>>& board, string word) {
		if (word.length() == 0)
			return true;
		else if (board.size() == 0)
			return false;

		unordered_set<int> s;
		int num = board.size() * board[0].size();
		for (int i = 0; i < num; i++)
		{
			int x = i / board[0].size(), y = i%board[0].size();
			s.insert(i);
			if (board[x][y] == word[0] && checkExist(board, word,1,i,s))
				return true;
			s.erase(i);
		}

		return false;
	}
};

int main()
{
	Solution s;
	vector<vector<char>> b = { 
		{ 'A', 'B', 'C', 'E' },
		{ 'S', 'F', 'C', 'S' },
		{ 'A', 'D', 'E', 'E' }
	};

	//cout << s.exist(b,"ABCCED") << endl;
	//cout << s.exist(b, "SEE") << endl;
	//cout << s.exist(b, "ABCB") << endl;

	vector<vector<char>> e = {
		{ 'C', 'A', 'A' },
		{ 'A', 'A', 'A' },
		{ 'B', 'C', 'D' }
	};

	cout << s.exist(e, "AAB") << endl;

	getchar();
	return 0;
}