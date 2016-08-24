#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int sLen = s.size(), pLen = p.size();
		vector<vector<bool>> match(sLen + 1, vector<bool>(p.size() + 1, false));
		
		for (int i = sLen; i >= 0; i--)
		{
			for (int j = pLen; j >= 0; j--)
			{
				if (i == sLen || j == pLen)
					match[i][j] = (i == sLen && j == pLen) || (j == pLen && sLen == 0) || (i == sLen && p[j] == '*' && match[i][j + 1]);
				else if (p[j] == '*')
					match[i][j] = match[i + 1][j] || match[i][j + 1];
				else
					match[i][j] = match[i + 1][j + 1] && (p[j] == '?' || p[j] == s[i]);
			}
		}

		return match[0][0];
	}
};


int main()
{
	Solution s;

	cout << s.isMatch("", "?") << endl;
	cout << s.isMatch("aa", "a") << endl;
	cout << s.isMatch("aaa", "aa") << endl;
	cout << s.isMatch("aab", "c*a*b") << endl;
	
	cout << s.isMatch("aa", "*") << endl;
	cout << s.isMatch("aa", "a*") << endl;
	cout << s.isMatch("ab", "?*") << endl;
	cout << s.isMatch("", "") << endl;
	cout << s.isMatch("aa", "aa") << endl;
	cout << s.isMatch("a", "a*") << endl;

	getchar();
	return 0;
}