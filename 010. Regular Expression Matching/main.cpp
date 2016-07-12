#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	//µÝ¹é
	/*bool isMatch(string s, string p) {		
		if (p.empty())
			return s.empty();
		
		if (p.size() == 1)
			return s.size() == 1 && (s[0] == p[0] || p[0] == '.');
		else
		{
			if (p[1] == '*')
				return isMatch(s, p.substr(2)) || (s.size() >= 1 && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));
			else
				return s.size() >= 1 && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1),p.substr(1));
		}
	}*/

	//¶¯Ì¬¹æ»®
	bool isMatch(string s, string p) {
		int sLen = s.size(), pLen = p.size();
		vector<vector<bool>> result(pLen + 1, vector<bool>(sLen + 1, false));

		for (int i = 0; i <= sLen; i++)
			result[0][i] = i == 0;
		for (int i = 0; i <= sLen && pLen > 0; i++)
			result[1][i] = i == 1 && (s[sLen - i] == p[pLen - 1] || p[pLen - 1] == '.');

		for (int i = 2; i <= pLen; i++)
		{
			for (int j = 0; j <= sLen; j++)
			{
				if (p[pLen - i + 1] == '*')
					result[i][j] = result[i - 2][j] || (j >= 1 && (s[sLen - j] == p[pLen - i] || p[pLen - i] == '.') && result[i][j - 1]);
				else
					result[i][j] = j >= 1 && (s[sLen - j] == p[pLen - i] || p[pLen - i] == '.') && result[i - 1][j - 1];
			}
		}

		return result[pLen][sLen];
	}
};

int main()
{
	Solution s;
	cout << s.isMatch("a", "") << endl;
	cout << s.isMatch("aaa", "aa") << endl;
	cout << s.isMatch("ab", ".*c") << endl;
	cout << s.isMatch("aa", "a*") << endl;
	cout << s.isMatch("aa", ".*") << endl;
	cout << s.isMatch("aab", "c*a*b") << endl;

	system("PAUSE");
	return 0;
}